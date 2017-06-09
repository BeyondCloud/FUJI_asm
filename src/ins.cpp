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

