<<<<<<< HEAD
#include "ins.h"
#include "map_tbl.h"

#include <string.h>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <bitset>


bool is_number(const string& s)
{
    string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
=======
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
void init_operand(string str,oprand_t &opr)
{

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
        opr.type = imm;
        if(val<256)
            opr.bits = 8;
        else if (val <65536)
            opr.bits = 16;
        else
            opr.bits = 32;
        opr.imm_val = val;
    }
    else
    {
        cout<<"operand type not found\n";
        opr.type = N_A;
    }

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
    //np stand for no prefix
    string str_np[2] ={string(pch[0]),string(pch[1])};

    //determine oprand type
    int opSrc_type,opDst_type;
    init_operand(str_np[0],opr1);
    init_operand(str_np[1],opr2);


    cout<<opr1.type<<"\t";
    cout<<opr2.type<<"\t";

    //generate corresponded opcode
    string opstr;
    bool same_size = (opr1.bits ==opr2.bits);
    //8 opcode bits
    opstr = "????";
    if(type_imm(opr1))
    {
        if(opr1.bits == 8)
        {
            if(type_rm16_32(opr2))
                opstr = "10000011";
            else if(type_rm8(opr2))
                opstr = "10000000";
            else if(str_np[1] == "al")
                opstr = "00000100";
        }
        else if(type_regA(opr2) && same_size )
                opstr = "00000101";
        else if(  type_r16_32(opr2) && same_size)
                opstr = "10000001";
    }
    else if(type_r(opr1))
    {
        if(same_size)
        {
            if(type_rm8(opr2))
                opstr = "00000000";
            else if(type_rm16_32(opr2))
                opstr = "00000001";
        }

    }
    else if(type_r(opr2))
    {
        if(same_size)
        {
            if(type_rm8(opr1))
                opstr = "00000000";
            else if(type_rm16_32(opr1))
                opstr = "00000001";
        }
    }

    //MOD bit , I won't immlement indirect addressing
    if(opr1.type == reg)
        opstr+="11";
    else if(type_imm(opr1))
        opstr+="00";

    if(type_r(opr1)&& type_r(opr2))
    {

        opstr += opr1.reg_val;
        opstr += opr2.reg_val;
    }
    else if(type_imm(opr1) && type_rm16_32(opr2))
    {
        opstr += "000"; //op extension ,000 for add imm32
        opstr += reg32_tbl[str_np[1]];
        size_t tmp = opr1.bits;
        switch (opr1.bits)
        {
            case 8:
                opstr+=bitset<8>(opr1.imm_val).to_string();
            break;
            case 16:
                opstr+=bitset<16>(opr1.imm_val).to_string();
            break;
            case 32:
                opstr+=bitset<32>(opr1.imm_val).to_string();
            break;

        }
    }
/*

    //else if(opSrc_type ==imm32 && ((opDst_type==reg32)||(opDst_type==mem32)))
    if(opSrc_type ==imm8 && rm_16_32(opDst_type))
    {

        opstr += "11"; //MOD
        opstr += "000"; //op extension ,000 for add imm32
        opstr += reg32_tbl[str_np[1]];
        if(stoi( str_np[0])<256)
            opstr+=bitset<8>(stoi(str_np[0])).to_string();
        else if(stoi( str_np[0])<65536)
            opstr+=bitset<16>(stoi(str_np[0])).to_string();
        else
            opstr+=bitset<32>(stoi(str_np[0])).to_string();
    }
*/
    cout<<str_bin2hex(opstr)<<"\t"<<opstr<<endl;


>>>>>>> 2edb4f644e43953c20c5b8336346f38c01e6e205
}
//return enum of operand_type ,such as reg32,imm..
int get_operand_type(string str_no_prefix)
{
    operand_type optype;
    if(reg32_tbl.find(str_no_prefix) != reg32_tbl.end())
        optype = reg32;
    //    cout<<pch<<" is r32\n"<<endl;
    else if(is_number(str_no_prefix))
        optype = imm;
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
//support imm2reg , mem2reg
void add(char* chp1,char* chp2)
{
    char* pch[2];


    int optype[2];

    pch[0] = strtok(chp1,"$%");
    pch[1] = strtok(chp2,"$%");

    string str_no_prefix[2] ={string(pch[0]),string(pch[1])};
    optype[0] = get_operand_type(str_no_prefix[0]);
    optype[1] = get_operand_type(str_no_prefix[1]);
    cout<<optype[0]<<"\t";
    cout<<optype[1]<<"\t";

    string opstr;
    if(optype[0] ==reg32 &&optype[1] ==reg32 )
    {
        opstr = "00000001";
        opstr += "11";//MOD bit,11 means R/M is register
        opstr += reg32_tbl[str_no_prefix[0]];
        opstr += reg32_tbl[str_no_prefix[1]];
    }
    else if(optype[0] ==imm &&optype[1] ==reg32 )
    {
        opstr = "10000011";//bit one set to 1 means imm
        opstr += "11"; //MOD
        opstr += "000"; //op extension ,000 for add imm
        opstr += reg32_tbl[str_no_prefix[1]];
        if(stoi( str_no_prefix[0])<256)
            opstr+=bitset<8>(stoi(str_no_prefix[0])).to_string();
        else if(stoi( str_no_prefix[0])<65536)
            opstr+=bitset<16>(stoi(str_no_prefix[0])).to_string();
        else
            opstr+=bitset<32>(stoi(str_no_prefix[0])).to_string();
    }

    cout<<str_bin2hex(opstr)<<"\t"<<opstr<<endl;
}

