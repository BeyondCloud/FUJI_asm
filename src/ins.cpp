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
void init_operand_type(string str,oprand_t &opr)
{
    operand_type optype;
    opr.name = str;
    if(tbl_find(reg32_tbl,str))
    {
        opr.bits = 32;
        opr.type = reg;
        opr.reg_val = reg32_tbl[str];
    }
    else if(tbl_find(reg16_tbl,str))
    {
        opr.bits = 16;
        opr.type = reg;
        opr.reg_val = reg16_tbl[str];
    }
    else if(tbl_find(reg8_tbl,str))
    {
        opr.bits = 8;
        opr.type = reg;
        opr.reg_val = reg8_tbl[str];
    }
    else if(is_number(str))
    {
        unsigned long int val = stoi(str);
        assert(val<=4294967295);
        if(val<256)
        {
            opr.bits = 8;
            opr.type = imm8;
        }
        else if (val <65536)
        {
            opr.bits = 16;
            opr.type = imm16;
        }
        else
        {
            opr.bits = 32;
            opr.type = imm32;
        }
        opr.imm_val = val;
    }
    else
    {
        cout<<"operand type not found\n";
        opr.type = N_A;
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
    init_operand(str_no_prefix[0],str_no_prefix[1]);

    cout<<opr1.type<<"\t";
    cout<<opr2.type<<"\t";

    //generate corresponded opcode
    string opstr;
    bool same_size = (opr1.bits ==opr2.bits);
    //8 opcode bits
    //first bit determine immediate mode
    //but if you use

    if(type_imm(opr1)&& type_regA(opr2)&&same_size)
        opstr = "1";
    else
        opstr = "0";

    opstr+="0000";

    if(same_size && type_regA(opr2) && type_imm(opr1))
        opstr+="1";
    else
        opstr+="0";

    //d bit
    //mem to reg
    if(type_rm(opr1) && type_rm(r) && same_size)
        opstr+="1";
    else if(type_imm8(opr1) && type_rm16_32(opr2) )
        opstr+="1";
    else if(opr1.type == reg && opr2.type == reg && same_size)
        opstr+="0";
    else if(opr1.type == reg && opr2.type == mem && same_size)
        opstr+="0";


    //s bit
        //d bit
        if(rm_all(opSrc_type) ||regA_all(str_no_prefix[0]))
            opstr+="1";
        else
            opstr+="0";
        //s bit



    if(opSrc_type ==r32 && opDst_type ==r32 )
    {

        opstr += "11";//MOD bit,11 means R/M is register
        opstr += reg32_tbl[str_no_prefix[0]];
        opstr += reg32_tbl[str_no_prefix[1]];
    }
    //else if(opSrc_type ==imm32 && ((opDst_type==reg32)||(opDst_type==mem32)))
    else if(opSrc_type ==imm8 && rm_16_32(opDst_type))
    {

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
    else if(opSrc_type ==imm32 && r_16_32(opDst_type))
    {


    }
    cout<<str_bin2hex(opstr)<<"\t"<<opstr<<endl;


}

