#ifndef __INS_H
#define __INS_H
#include <string>
using namespace std;
enum operand_type{reg32=1,imm};
bool is_number(const string& s);
int get_operand_type(string str_no_prefix);
void add(char* str1,char* str2);
string str_bin2hex(string bin);
#endif
