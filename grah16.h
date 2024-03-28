#ifndef GRAH16_H
#define GRAH16_H

#define mir 0
#define ar0 1
#define ar1 2
#define ar2 3
#define ar3 4
#define ar4 5
#define ar5 6
#define ar6 7
#define ar7 8
#define cpr 9
#define rar 10
#define isc 11
#define ra8 12
#define ra16 13

void inst_nop();  // no operation                                                    000000
void inst_mov();  // moves first arg to second                                       000001
void inst_add();  // add arg1 and arg2 save in arg3                                  000010
void inst_sub();  // sub arg1 and arg2 save in arg3                                  000011
void inst_mul();  // mul arg1 and arg2 save in arg3                                  000100
void inst_div();  // div arg1 and arg2 save in arg3                                  000101
void inst_not();  // not arg1 and save in arg2                                       000110
void inst_and();  // and arg1 and arg2 save in arg3                                  000111
void inst_nand(); // nand arg1 and arg2 save in arg3                                 001000
void inst_or();   // or arg1 and arg2 save in arg3                                   001001
void inst_nor();  // nor arg1 and arg2 save in arg3                                  001010
void inst_xor();  // xor arg1 and arg2 save in arg3                                  001011
void inst_nxor(); // nxor arg1 and arg2 save in arg3                                 001100
void inst_shl();  // shift to left arg1 times arg2 saves in arg3                     001101
void inst_shr();  // shift to right arg1 times arg2 saves in arg3                    001110
void inst_jmp();  // set instruction counter to arg1 (can use label)                 001111
void inst_jz();   // jump if cpr(register) = 0   (can use label)                     010000
void inst_jnz();  // jump if cpr(register) != 0  (can use label)                     010001
void inst_equ();  // if arg1 = arg2 cpr = 1 else cpr = 0                             000001
void inst_neq();  // if arg1 != arg2 cpr = 1 else cpr = 0                            000001
void inst_grt();  // if arg1 > arg2 cpr = 1 else cpr = 0                             000001
void inst_grq();  // if arg1 >= arg2 cpr = 1 else cpr = 0                            000001
void inst_les();  // if arg1 < arg2 cpr = 1 else cpr = 0                             000001
void inst_leq();  // if arg1 <= arg2 cpr = 1 else cpr = 0                            000001
void inst_grts(); // if arg1 > arg2 cpr = 1 else cpr = 0 (singed(negative numbers))  000001
void inst_grqs(); // if arg1 >= arg2 cpr = 1 else cpr = 0 (singed(negative numbers)) 000001
void inst_less(); // if arg1 < arg2 cpr = 1 else cpr = 0 (singed(negative numbers))  000001
void inst_leqs(); // if arg1 <= arg2 cpr = 1 else cpr = 0 (singed(negative numbers)) 000001
void inst_call(); // push function on stack (label or num (offset))  000001
void inst_ret();  // pop function form stack 000001
void inst_push(); // push on stack arg1 000001
void inst_pop();  // pop value form stack save in arg1 000001
void inst_qin();  // put arg1 in queue 000001
void inst_qout(); // take first form queue to arg1 000001
void inst_imm();  // value(arg1) move to arg2 (16bit values - 1bit (max != 65535; max = 32767))  000001
void inst_intcall(); // calls interpreter to exicute a function                                  000001

#endif //!GRAH16_H