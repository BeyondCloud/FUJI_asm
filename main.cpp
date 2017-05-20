// reading a text file
#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <map>
#include  <iomanip>
#include  "ins.h"
#include  <assert.h>

using namespace std;
typedef void (*op_fp)(string &str1,string &str2);
ifstream infile("in_file.s");
ofstream outfile ("example.txt");

/*
string get_opcode(char* code)
{
   // scanf("%s",&instr);
   int num  = op_tbl(code);
   //cout<<code<<endl;
    switch(num)
    {
        case 1:
            return "01C3";
        break;
    }
    return code;
}
*/
map<string, op_fp> op_tbl;
map<string, op_fp>::iterator iter;
//eax 000 , ebx 011 ,ecx 001 ,edx  010
void tbl_init()
{
    op_tbl["add"] = add;//01C3  add %eax, %ebx

    /*
    op_tbl["sub"] = sub;
    op_tbl["mul"] = mul; // F7E0  mul %eax
    op_tbl["div"] = div;

    //immediate address
    op_tbl["mov"]= mov; //B8+r (r: register)
    op_tbl["cmp"]= cmp;//39C3 cmp %eax , %ebx


    op_tbl["jmp"]= ;//
    //note: jxx will change opcode if jump too far
    op_tbl["ja"]= ja;//
    op_tbl["jae"]=jae;//
    op_tbl["jb"]= jb;//jb jc same op code?
    op_tbl["jbe"]=jbe;//
    op_tbl["jc"]= jc;//
    op_tbl["jcxz"]= jcxz;//

    op_tbl["je"]= je;//
    op_tbl["jg"]= jg;//
    op_tbl["jge"]=jge;//
    op_tbl["jl"]= jl;//
    op_tbl["jle"]=jle;//

    op_tbl["call"]=call;//
    op_tbl["ret"]= ret;//
*/

}
/*
void get_tbl_code(map<string,op_fp> M ,string str)
{
    iter = M.find(str);
    if(iter != M.end())
        return iter->second;
    else
       return str;
}
*/
int main () {
    tbl_init();
    assert(infile.is_open());
    string line;
    static int line_counter = 0;
    char *pch;
    while( getline (infile,line) )
    {
      char str[64];
      strcpy(str,line.c_str());
      pch = strtok (str," \t,");
      int arg_cnt = 0;
      string mnem[3];
      while (pch != NULL)
      {

        //outfile<< setfill('0') << setw(4)<<hex<<line_counter<<"\t";
        //outfile<<get_tbl_code(op_tbl,pch)<<"\n";
        //line_counter+=2;
        mnem[arg_cnt] = pch;
        pch = strtok (NULL, " \t,$");
        arg_cnt++;
      }
      op_tbl[mnem[0]](mnem[1],mnem[2]);
      cout<<endl;

    }


    //cout<<"Done,output file to example.txt";
    infile.close();


}
