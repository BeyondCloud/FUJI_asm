#include "map_tbl.h"
#include "ins.h"
map<string, op_fp> op_tbl;
map<string, string> reg32_tbl;
map<string, string> reg16_tbl;
map<string, string> reg8_tbl;
map<string, string> mod_tbl;

void tbl_init()
{
    reg32_tbl["eax"] = "000";
    reg32_tbl["ecx"] = "001";
    reg32_tbl["edx"] = "010";
    reg32_tbl["ebx"] = "011";
    reg32_tbl["esp"] = "100";
    reg32_tbl["ebp"] = "101";
    reg32_tbl["esi"] = "110";
    reg32_tbl["edi"] = "111";

    reg16_tbl["ax"] = "000";
    reg16_tbl["cx"] = "001";
    reg16_tbl["dx"] = "010";
    reg16_tbl["bx"] = "011";
    reg16_tbl["sp"] = "100";
    reg16_tbl["bp"] = "101";
    reg16_tbl["si"] = "110";
    reg16_tbl["di"] = "111";

    reg8_tbl["al"] = "000";
    reg8_tbl["cl"] = "001";
    reg8_tbl["dl"] = "010";
    reg8_tbl["bl"] = "011";
    reg8_tbl["ah"] = "100";
    reg8_tbl["ch"] = "101";
    reg8_tbl["dh"] = "110";
    reg8_tbl["bh"] = "111";

    mod_tbl["ah"] = "100";
    mod_tbl["ch"] = "101";
    mod_tbl["dh"] = "110";
    mod_tbl["bh"] = "111";

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
