// reading a text file

#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <map>
#include  <iomanip>
#include  <assert.h>
#include  "ins.h"
#include  "map_tbl.h"



using namespace std;

ifstream infile("in_file.s");
ofstream outfile ("example.txt");
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
      string mnem;
      char* oprand[2];
      while (pch != NULL)
      {

        //outfile<< setfill('0') << setw(4)<<hex<<line_counter<<"\t";
        if(arg_cnt==0)
            mnem = pch;
        else
            oprand[arg_cnt-1] = pch;
        //pch = strtok (NULL, " \t,$");
        pch = strtok (NULL, " \t,");
        arg_cnt++;
      }
      cout<<line_counter<<"\t";
      op_tbl[mnem](oprand[0],oprand[1]);
      cout<<endl;
      line_counter++;

    }


    //cout<<"Done,output file to example.txt";
    infile.close();


}
