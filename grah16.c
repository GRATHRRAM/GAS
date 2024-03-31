#define GRAH16_C

#include <stdint.h>
#include <stdio.h>

#ifdef WIN32
#include <windows.h>
#define sleep Sleep(100)
#else
#include <unistd.h>
#define sleep usleep(100 * 1000)
#endif

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
    uint16_t *mainr;
    uint16_t *arg0;
    uint16_t *arg1;
    uint16_t *arg2;
    uint16_t *arg3;
    uint16_t *arg4;
    uint16_t *arg5;
    uint16_t *arg6;
    uint16_t *arg7;
} argptrs;


void inst_nop(){sleep;}                                                         
void inst_mov(uint16_t *arg1, uint16_t *arg2)                   {*arg2 = *arg1;}
void inst_add(uint16_t arg1, uint16_t arg2, uint16_t *arg3)     {*arg3 = arg1 + arg2;}
void inst_sub(uint16_t arg1, uint16_t arg2, uint16_t *arg3)     {*arg3 = arg1 - arg2;}
void inst_mul(uint16_t arg1, uint16_t arg2, uint16_t *arg3)     {*arg3 = arg1 * arg2;}                                          
void inst_div(uint16_t arg1, uint16_t arg2, uint16_t *arg3)     {*arg3 = arg1 / arg2;}
void inst_not(uint16_t arg1, uint16_t *arg2)                    {*arg2 = ~arg1;}
void inst_and(uint16_t arg1, uint16_t arg2, uint16_t *arg3)     {*arg3 = arg1 & arg2;}
void inst_nand(uint16_t arg1, uint16_t arg2, uint16_t *arg3)    {*arg3 = ~(arg1 & arg2);}
void inst_or(uint16_t arg1, uint16_t arg2, uint16_t *arg3)      {*arg3 = arg1 | arg2;}   
void inst_nor(uint16_t arg1, uint16_t arg2, uint16_t *arg3)     {*arg3 = ~(arg1 | arg2);} 
void inst_xor(uint16_t arg1, uint16_t arg2, uint16_t *arg3)     {*arg3 = arg1 ^ arg2;}  
void inst_nxor(uint16_t arg1, uint16_t arg2, uint16_t *arg3)    {*arg3 = ~(arg1 ^ arg2);}; 
void inst_shl(uint16_t arg1, uint16_t arg2, uint16_t *arg3)     {*arg3 = arg1 << arg2;}  
void inst_shr(uint16_t arg1, uint16_t arg2, uint16_t *arg3)     {*arg3 = arg1 >> arg2;}
void inst_jmp(uint16_t arg1, uint16_t *isc_reg)                 {*isc_reg = arg1;}
void inst_jz(uint16_t arg1, uint16_t *isc_reg, uint8_t cpr_reg) {if(cpr_reg == 0) *isc_reg = arg1;}                                  
void inst_jnz(uint16_t arg1, uint16_t *isc_reg, uint8_t cpr_reg){if(cpr_reg != 0) *isc_reg = arg1;}
void inst_equ(uint16_t arg1, uint16_t arg2, uint8_t *cpr_reg)   {if(arg1 == arg2) *cpr_reg = 1;else *cpr_reg = 0;}
void inst_neq(uint16_t arg1, uint16_t arg2, uint8_t *cpr_reg)   {if(arg1 != arg2) *cpr_reg = 1;else *cpr_reg = 0;}
void inst_grt(uint16_t arg1, uint16_t arg2, uint8_t *cpr_reg)   {if(arg1 > arg2) *cpr_reg = 1;else *cpr_reg = 0;}
void inst_grq(uint16_t arg1, uint16_t arg2, uint8_t *cpr_reg)   {if(arg1 >= arg2) *cpr_reg = 1;else *cpr_reg = 0;}
void inst_les(uint16_t arg1, uint16_t arg2, uint8_t *cpr_reg)   {if(arg1 < arg2) *cpr_reg = 1;else *cpr_reg = 0;}
void inst_leq(uint16_t arg1, uint16_t arg2, uint8_t *cpr_reg)   {if(arg1 <= arg2) *cpr_reg = 1;else *cpr_reg = 0;}
void inst_grts(int16_t arg1, int16_t arg2, uint8_t *cpr_reg)    {if(arg1 > arg2) *cpr_reg = 1;else *cpr_reg = 0;}
void inst_grqs(int16_t arg1, int16_t arg2, uint8_t *cpr_reg)    {if(arg1 >= arg2) *cpr_reg = 1;else *cpr_reg = 0;}
void inst_less(int16_t arg1, int16_t arg2, uint8_t *cpr_reg)    {if(arg1 < arg2) *cpr_reg = 1;else *cpr_reg = 0;}
void inst_leqs(int16_t arg1, int16_t arg2, uint8_t *cpr_reg)    {if(arg1 <= arg2) *cpr_reg = 1;else *cpr_reg = 0;}
void inst_call(uint16_t arg1, uint16_t *stack);
void inst_ret();
void inst_push(uint16_t arg1);
void inst_pop(uint16_t *arg1);
void inst_qin(uint16_t arg1);
void inst_qout(uint16_t *arg1);
void inst_imm(uint16_t arg1,uint16_t *arg2){*arg2 = arg1;}
void inst_hrdcall(argptrs *args);


void inst_hrdcall(argptrs *args){
    if(*args->mainr == 0)putchar(*args->arg0 + 48); //putnum
    if(*args->mainr == 1)putchar(*args->arg0);      //char
}