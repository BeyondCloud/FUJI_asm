#ifndef __INS_H
#define __INS_H
#include <string>
using namespace std;

#define tbl_find(tbl,str) (tbl.find(str) != tbl.end())

#define type_imm8(opr_t) (opr_t.type == imm && opr_t.bits == 8)
#define type_imm16(opr_t) (opr_t.type == imm && opr_t.bits == 16)
#define type_imm32(opr_t) (opr_t.type == imm && opr_t.bits == 32)
#define type_rm16_32(opr_t) (((opr_t.type == reg)||(opr_t.type == mem))&& \
                              ((opr_t.bits == 16)||(opr_t.bits == 32)))
#define type_r16_32(opr_t) ((opr_t.type == reg)&& \
                            ((opr_t.bits == 16)||(opr_t.bits == 32)))
#define type_rm8(opr_t) ((opr_t.type == reg ||opr_t.type == mem)&& opr_t.bits == 8)

#define type_r(opr_t) (opr_t.type == reg)
#define type_imm(opr_t) (opr_t.type == imm)

#define type_rm(opr_t) ((opr_t.type == reg)||(opr_t.type == mem))

#define type_regA(opr_t) ( opr_t.type == reg && opr_t.reg_val == "000")


/*
enum operand_type{  r8=1,
                    r16,
                    r32,
                    imm8,
                    imm16,
                    imm32,
                    m8,
                    m16,
                    m32,
                    not_found};
*/


typedef enum{reg,mem,imm,N_A} type_t;
static struct oprand_t
{
    string name; //ex: eax, ebx...
    int bits;
    int type;
    unsigned long int imm_val;
    string reg_val;

}opr1,opr2;

bool is_number(const string& s);

void init_operand(string str,oprand_t &opr);
string str_bin2hex(string bin);

void add(char* src_chp,char* dst_chp);


#endif
