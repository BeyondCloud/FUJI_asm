// reading a text file
#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <map>
#include  <iomanip>
using namespace std;

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
map<string, string> op_tbl;
map<string, string>::iterator iter;
//eax 000 , ebx 011 ,ecx 001 ,edx  010
void tbl_init()
{
    op_tbl["add"] = "000111";//01C3  add %eax, %ebx
    op_tbl["sub"] = "001010";
    op_tbl["mul"] = "1111011111100"; // F7E0  mul %eax
    op_tbl["div"] = "1111011111110";

    op_tbl["mov"]= "10111"; //B9030000 mov $3,%ecx
    op_tbl["cmp"]= "0011100111";//39C3 cmp %eax , %ebx


    op_tbl["jmp"]= "";//
    //note: jxx will change opcode if jump too far
    op_tbl["ja"]= "011101110";//
    op_tbl["jae"]="011100110";//
    op_tbl["jb"]= "011100100";//jb jc same op code?
    op_tbl["jbe"]="011101100";//
    op_tbl["jc"]= "011100100";//
    op_tbl["jcxz"]= "";//

    op_tbl["je"]= "0111";//
    op_tbl["jg"]= "0111";//
    op_tbl["jge"]="0111";//
    op_tbl["jl"]= "0111";//
    op_tbl["jle"]="0111";//



    op_tbl["call"]= "";//
    op_tbl["rt"]= "";//


}
string get_tbl_code(map<string, string> M ,string str)
{
    iter = M.find(str);
    if(iter != M.end())
        return iter->second;
    else
       return str;
}


int main () {
    tbl_init();
    char * pch;
    ifstream infile("test.s");
    ofstream outfile ("example.txt");
    if (!infile.is_open())
    {
      cout << "Unable to open file";
      return 0;
    }
    string line;
    static int line_counter = 0;
    while( getline (infile,line) )
    {
      char str[64];
      strcpy(str, line.c_str());
      pch = strtok (str," \t,");

      while (pch != NULL)
      {
        outfile<< setfill('0') << setw(4)<<hex<<line_counter<<"\t";
        outfile<<get_tbl_code(op_tbl,pch)<<"\n";
        pch = strtok (NULL, " \t,$");
        line_counter+=2;
      }


    }


    cout<<"Done,output file to example.txt";
    infile.close();


}
