// reading a text file
#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <map>
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
void tbl_init()
{
    op_tbl["add"] = "01C3";
    op_tbl["sub"] = "29C3";
    op_tbl["mul"] = "F7E0";
    op_tbl["div"] = "F7F0";
    op_tbl["movl"]= "C7050000";
    op_tbl["cmp"] = "39C3";
}
string get_tbl_value(map<string, string> M ,string str)
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
    while( getline (infile,line) )
    {
      char str[64];
      strcpy(str, line.c_str());
      pch = strtok (str," \t");
      while (pch != NULL)
      {
        outfile<<get_tbl_value(op_tbl,pch)<<"\n";
        pch = strtok (NULL, " \t");
      }

    }
    cout<<"Done,output file to example.txt";
    infile.close();


}
