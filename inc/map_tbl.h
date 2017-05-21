#ifndef __MAP_TBL_H
#define __MAP_TBL_H
#include <map>
#include <string>

using namespace std;
typedef void (*op_fp)(char* str1,char* str2);


extern map<string, op_fp> op_tbl;
extern map<string, string> reg32_tbl;
extern map<string, string> reg16_tbl;
extern map<string, string> reg8_tbl;
extern map<string, string> mod_tbl;
//map<string, op_fp>::iterator iter;
//eax 000 , ebx 011 ,ecx 001 ,edx  010
void tbl_init();

#endif
