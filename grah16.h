#ifndef GRAH16_H
#define GRAH16_H

#include <stdint.h>

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

typedef struct argptrs {
    uint16_t *arg0;
    uint16_t *arg1;
    uint16_t *arg2;
    uint16_t *arg3;
    uint16_t *arg4;
    uint16_t *arg5;
    uint16_t *arg6;
    uint16_t *arg7;
} argptrs;

void inst_nop();                                              // no operation                                                                000000
void inst_mov(uint16_t *arg1, uint16_t *arg2);                // moves first arg to                                                          000001
void inst_add(uint16_t arg1, uint16_t arg2, uint16_t *arg3);  // add arg1 and arg2 save in arg3                                              000010
void inst_sub(uint16_t arg1, uint16_t arg2, uint16_t *arg3);  // sub arg1 and arg2 save in arg3                                              000011
void inst_mul(uint16_t arg1, uint16_t arg2, uint16_t *arg3);  // mul arg1 and arg2 save in arg3                                              000100
void inst_div(uint16_t arg1, uint16_t arg2, uint16_t *arg3);  // div arg1 and arg2 save in arg3                                              000101
void inst_not(uint16_t arg1, uint16_t *arg2);                 // not arg1 and save in arg2                                                   000110
void inst_and(uint16_t arg1, uint16_t arg2, uint16_t *arg3);  // and arg1 and arg2 save in arg3                                              000111
void inst_nand(uint16_t arg1, uint16_t arg2, uint16_t *arg3); // nand arg1 and arg2 save in arg3                                             001000
void inst_or(uint16_t arg1, uint16_t arg2, uint16_t *arg3);   // or arg1 and arg2 save in arg3                                               001001
void inst_nor(uint16_t arg1, uint16_t arg2, uint16_t *arg3);  // nor arg1 and arg2 save in arg3                                              001010
void inst_xor(uint16_t arg1, uint16_t arg2, uint16_t *arg3);  // xor arg1 and arg2 save in arg3                                              001011
void inst_nxor(uint16_t arg1, uint16_t arg2, uint16_t *arg3); // nxor arg1 and arg2 save in arg3                                             001100
void inst_shl(uint16_t arg1, uint16_t arg2, uint16_t *arg3);  // shift to left arg1 times arg2 saves in arg3                                 001101
void inst_shr(uint16_t arg1, uint16_t arg2, uint16_t *arg3);  // shift to right arg1 times arg2 saves in arg3                                001110
void inst_jmp(uint16_t arg1);                                 // set instruction counter to arg1 (can use label)                             001111
void inst_jz(uint16_t arg1);                                  // jump if cpr(register) = 0   (can use label)                                 010000
void inst_jnz(uint16_t arg1);                                 // jump if cpr(register) != 0  (can use label)                                 010001
void inst_equ(uint16_t arg1, uint16_t arg2);                  // if arg1 = arg2 cpr = 1 else cpr = 0                                         010010
void inst_neq(uint16_t arg1, uint16_t arg2);                  // if arg1 != arg2 cpr = 1 else cpr = 0                                        010011
void inst_grt(uint16_t arg1, uint16_t arg2);                  // if arg1 > arg2 cpr = 1 else cpr = 0                                         010100
void inst_grq(uint16_t arg1, uint16_t arg2);                  // if arg1 >= arg2 cpr = 1 else cpr = 0                                        010101
void inst_les(uint16_t arg1, uint16_t arg2);                  // if arg1 < arg2 cpr = 1 else cpr = 0                                         010110
void inst_leq(uint16_t arg1, uint16_t arg2);                  // if arg1 <= arg2 cpr = 1 else cpr = 0                                        010111
void inst_grts(int16_t arg1, int16_t arg2);                   // if arg1 > arg2 cpr = 1 else cpr = 0 (singed(negative numbers))              011000
void inst_grqs(int16_t arg1, int16_t arg2);                   // if arg1 >= arg2 cpr = 1 else cpr = 0 (singed(negative numbers))             011001
void inst_less(int16_t arg1, int16_t arg2);                   // if arg1 < arg2 cpr = 1 else cpr = 0 (singed(negative numbers))              011010
void inst_leqs(int16_t arg1, int16_t arg2);                   // if arg1 <= arg2 cpr = 1 else cpr = 0 (singed(negative numbers))             011011
void inst_call(uint16_t arg1);                                // push function on stack (label or num (offset))                              011100
void inst_ret();                                              // pop function form stack                                                     011101
void inst_push(uint16_t arg1);                                // push on stack arg1                                                          011111
void inst_pop(uint16_t *arg1);                                // pop value form stack save in arg1                                           100000
void inst_qin(uint16_t arg1);                                 // put arg1 in queue                                                           100001
void inst_qout(uint16_t *arg1);                               // take first form queue to arg1                                               100010
void inst_imm(uint16_t arg1,uint16_t *arg2);                  // value(arg1) move to arg2 (16bit values - 1bit (max != 65535; max = 32767))  100011
void inst_intcall(argptrs *args);                             // calls interpreter to exicute a function                                     100100

#endif //!GRAH16_H