#include "ins.h"
#include "map_tbl.h"

#include <string.h>
#include  <assert.h>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <bitset>


bool is_number(const string& s)
{
    string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}
//return enum of operand_type ,such as reg32,imm32..
int get_operand_type(string str)
{
    operand_type optype;
    if(tbl_find(reg32_tbl,str))
        optype = reg32;
    else if(tbl_find(reg16_tbl,str))
        optype = reg16;
    else if(tbl_find(reg8_tbl,str))
        optype = reg8;
    else if(is_number(str))
    {
        unsigned long int val = stoi(str);
        assert(val<=4294967295);
        if(val<256)
            optype = imm8;
        else if (val <65536)
            optype = imm16;
        else
            optype = imm32;

    }
    else
    {
        cout<<"operand type not found\n";
        optype = not_found;
    }
    return optype;
}
string str_bin2hex(string bin)
{
    int result =0;
    int len = bin.length()/4;
    for(size_t count = 0; count < bin.length() ; ++count)
    {
        result *=2;
        result += (bin[count]=='1')? 1 :0;
    }
    stringstream ss;
    ss << hex << setw(len) << setfill('0')  << result;
    string hexVal(ss.str());
    return hexVal;

}

void add(char* src_chp,char* dst_chp)
{


    //remove prefix
    char* pch[2];
    pch[0] = strtok(src_chp,"$%");
    pch[1] = strtok(dst_chp,"$%");
    string str_no_prefix[2] ={string(pch[0]),string(pch[1])};

    //determine oprand type
    int opSrc_type,opDst_type;
    opSrc_type = get_operand_type(str_no_prefix[0]);
    opDst_type = get_operand_type(str_no_prefix[1]);
    cout<<opSrc_type<<"\t";
    cout<<opDst_type<<"\t";

    //generate corresponded opcode
    string opstr;
    if(opSrc_type ==reg32 && opDst_type ==reg32 )
    {
        opstr = "00000001";
        opstr += "11";//MOD bit,11 means R/M is register
        opstr += reg32_tbl[str_no_prefix[0]];
        opstr += reg32_tbl[str_no_prefix[1]];
    }
    //else if(opSrc_type ==imm32 && ((opDst_type==reg32)||(opDst_type==mem32)))
    else if(opSrc_type ==imm8 && rm_16_32(opDst_type))
    {
        opstr = "10000011";//bit one set to 1 means imm32
        opstr += "11"; //MOD
        opstr += "000"; //op extension ,000 for add imm32
        opstr += reg32_tbl[str_no_prefix[1]];
        if(stoi( str_no_prefix[0])<256)
            opstr+=bitset<8>(stoi(str_no_prefix[0])).to_string();
        else if(stoi( str_no_prefix[0])<65536)
            opstr+=bitset<16>(stoi(str_no_prefix[0])).to_string();
        else
            opstr+=bitset<32>(stoi(str_no_prefix[0])).to_string();
    }
    else if(opSrc_type ==imm32 && opDst_type ==reg32 )
    {


    }
    cout<<str_bin2hex(opstr)<<"\t"<<opstr<<endl;


}

