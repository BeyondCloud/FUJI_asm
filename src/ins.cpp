#include "ins.h"
#include "map_tbl.h"

#include <string.h>
#include <iostream>
bool is_number(const string& s)
{
    string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}
//return enum of operand_type ,such as reg32,imm..
int get_operand_type(string str)
{
    operand_type optype;
    if(reg32_tbl.find(str) != reg32_tbl.end())
        optype = reg32;
    //    cout<<pch<<" is r32\n"<<endl;
    else if(is_number(str))
        optype = imm;
    return optype;
}
void add(char* chp1,char* chp2)
{
    char* pch[2];
    pch[0] = strtok (chp1,"$%");
    pch[1] = strtok (chp2,"$%");

    string str1 = string(pch[0]);
    string str2 = string(pch[1]);


    int optype[2];

    optype[0] = get_operand_type(str1);
    optype[1] = get_operand_type(str2);
    cout<<optype[0]<<"\t";
    cout<<optype[1]<<"\t";

    string opstr;
    if(optype[0] ==reg32 &&optype[1] ==reg32 )
    {
        opstr = "00000001";
        opstr += reg32_tbl[str1];
        opstr += reg32_tbl[str2];
    }
    cout<<opstr<<endl;


  //  cout<<pch<<"\t";
  //  pch = strtok (str2,"$%");
  //  cout<<pch;
}

