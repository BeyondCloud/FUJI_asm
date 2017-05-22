#ifndef __INS_H
#define __INS_H
#include <string>
using namespace std;

#define tbl_find(tbl,str) (tbl.find(str) != tbl.end())
#define rm_16_32(x) ((x==reg16)||(x==reg32)||(x==mem16)||(x==mem32))
#define r_16_32(x) ((x==reg16)||(x==reg32))

enum operand_type{  reg8=1,
                    reg16=1,
                    reg32=1,
                    imm8,
                    imm16,
                    imm32,
                    mem8,
                    mem16,
                    mem32,
                    not_found};
bool is_number(const string& s);
int get_operand_type(string str);
string str_bin2hex(string bin);
void add(char* src_chp,char* dst_chp);


#endif
