#ifndef GRAH16_H
#define GRAH16_H

#include <stdint.h>

#define ar0 0 //first arg
#define ar1 1 //second arg
#define ar2 2 //third arg 
#define ar3 3 //fourth arg
#define ar4 4 //fifth arg
#define ar5 5 //sixth arg
#define ar6 6 //seventh arg
#define ar7 7 //eighth arg

#define gp0 8  // general purpose regiser
#define gp1 9  // general purpose regiser
#define gp2 10 // general purpose regiser
#define gp3 11 // general purpose regiser
#define gp4 12 // general purpose regiser
#define gp5 13 // general purpose regiser
#define gp6 14 // general purpose regiser
#define gp7 15 // general purpose regiser

#define mir 16 // main regiser (used as function choser in hrdcall)
#define rar 17 // ram addres regiser (ram pointer)
#define cpr 18 // comparisons regiser stores resoults from instruction like equ,less,grt 
#define isc 19 // instruction counter (change only if you jump)

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

void inst_nop();                                              //00 no operation                                                                000000
void inst_mov(uint16_t *arg1, uint16_t *arg2);                //01 moves first arg to                                                          000001
void inst_add(uint16_t arg1, uint16_t arg2, uint16_t *arg3);  //02 add arg1 and arg2 save in arg3                                              000010
void inst_sub(uint16_t arg1, uint16_t arg2, uint16_t *arg3);  //03 sub arg1 and arg2 save in arg3                                              000011
void inst_mul(uint16_t arg1, uint16_t arg2, uint16_t *arg3);  //04 mul arg1 and arg2 save in arg3                                              000100
void inst_div(uint16_t arg1, uint16_t arg2, uint16_t *arg3);  //05 div arg1 and arg2 save in arg3                                              000101
void inst_not(uint16_t arg1, uint16_t *arg2);                 //06 not arg1 and save in arg2                                                   000110
void inst_and(uint16_t arg1, uint16_t arg2, uint16_t *arg3);  //07 and arg1 and arg2 save in arg3                                              000111
void inst_nand(uint16_t arg1, uint16_t arg2, uint16_t *arg3); //08 nand arg1 and arg2 save in arg3                                             001000
void inst_or(uint16_t arg1, uint16_t arg2, uint16_t *arg3);   //09 or arg1 and arg2 save in arg3                                               001001
void inst_nor(uint16_t arg1, uint16_t arg2, uint16_t *arg3);  //0A nor arg1 and arg2 save in arg3                                              001010
void inst_xor(uint16_t arg1, uint16_t arg2, uint16_t *arg3);  //0B xor arg1 and arg2 save in arg3                                              001011
void inst_nxor(uint16_t arg1, uint16_t arg2, uint16_t *arg3); //0C nxor arg1 and arg2 save in arg3                                             001100
void inst_shl(uint16_t arg1, uint16_t arg2, uint16_t *arg3);  //0D shift to left arg1 times arg2 saves in arg3                                 001101
void inst_shr(uint16_t arg1, uint16_t arg2, uint16_t *arg3);  //0E shift to right arg1 times arg2 saves in arg3                                001110
void inst_jmp(uint16_t arg1);                                 //0F set instruction counter to arg1 (can use label)                             001111
void inst_jz(uint16_t arg1);                                  //10 jump if cpr(register) = 0   (can use label)                                 010000
void inst_jnz(uint16_t arg1);                                 //11 jump if cpr(register) != 0  (can use label)                                 010001
void inst_equ(uint16_t arg1, uint16_t arg2);                  //12 if arg1 = arg2 cpr = 1 else cpr = 0                                         010010
void inst_neq(uint16_t arg1, uint16_t arg2);                  //13 if arg1 != arg2 cpr = 1 else cpr = 0                                        010011
void inst_grt(uint16_t arg1, uint16_t arg2);                  //14 if arg1 > arg2 cpr = 1 else cpr = 0                                         010100
void inst_grq(uint16_t arg1, uint16_t arg2);                  //15 if arg1 >= arg2 cpr = 1 else cpr = 0                                        010101
void inst_les(uint16_t arg1, uint16_t arg2);                  //16 if arg1 < arg2 cpr = 1 else cpr = 0                                         010110
void inst_leq(uint16_t arg1, uint16_t arg2);                  //17 if arg1 <= arg2 cpr = 1 else cpr = 0                                        010111
void inst_grts(int16_t arg1, int16_t arg2);                   //18 if arg1 > arg2 cpr = 1 else cpr = 0 (singed(negative numbers))              011000
void inst_grqs(int16_t arg1, int16_t arg2);                   //19 if arg1 >= arg2 cpr = 1 else cpr = 0 (singed(negative numbers))             011001
void inst_less(int16_t arg1, int16_t arg2);                   //1A if arg1 < arg2 cpr = 1 else cpr = 0 (singed(negative numbers))              011010
void inst_leqs(int16_t arg1, int16_t arg2);                   //1B if arg1 <= arg2 cpr = 1 else cpr = 0 (singed(negative numbers))             011011
void inst_call(uint16_t arg1);                                //1C push function on stack (label or num (offset))                              011100
void inst_ret();                                              //1D pop function form stack                                                     011101
void inst_push(uint16_t arg1);                                //1E push on stack arg1                                                          011111
void inst_pop(uint16_t *arg1);                                //1F pop value form stack save in arg1                                           100000
void inst_qin(uint16_t arg1);                                 //20 put arg1 in queue                                                           100001
void inst_qout(uint16_t *arg1);                               //21 take first form queue to arg1                                               100010
void inst_imm(uint16_t arg1,uint16_t *arg2);                  //23 value(arg1) move to arg2 (16bit values - 1bit (max != 65535; max = 32767))  100011
void inst_hrdcall(argptrs *args);                             //24 hardcall => hardwarecall works like syscall                                 100100
void inst_ra8(uint16_t arg1, uint16_t *arg2);                 //25 gets 8bit value from ram(rar regiser its pointer)                           100101
void inst_ra16(uint16_t *arg1);                               //26 gets 16bit value from ram(rar regiser its pointer)                          100110

#endif //!GRAH16_H