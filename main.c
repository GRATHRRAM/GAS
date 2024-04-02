#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "conv.h"
#include "grah16.h"

uint8_t checkend(char* string);

typedef struct registers {
    uint16_t reg_ar0,reg_ar1,reg_ar2,reg_ar3,
    reg_ar4,reg_ar5,reg_ar6,reg_ar7,
    reg_gp0,reg_gp1,reg_gp2,reg_gp3,reg_gp4,
    reg_gp5,reg_gp6,reg_gp7,reg_mir,reg_rar,
    reg_cpr,reg_isc;
} registers;

int main(int argc, char **argv) {//dont look at this mess
    if(argc > 1) {
        uint8_t info = checkend(argv[1]);
        if(info == 1) conv_asm_to_hex(argv[1]);
        else if(info == 2){
            FILE *file;
            file = fopen(argv[1], "r");
            if(file == NULL) return 1;

            char buff[255];
            uint16_t inst[4];
            uint16_t *arg1,*arg2,*arg3;
            registers regs = {0};
            argptrs argp = {0};
            argp.mainr = &regs.reg_mir;
            argp.arg0 = &regs.reg_ar0;
            argp.arg1 = &regs.reg_ar1;
            argp.arg2 = &regs.reg_ar2;
            argp.arg3 = &regs.reg_ar3;
            argp.arg4 = &regs.reg_ar4;
            argp.arg5 = &regs.reg_ar5;
            argp.arg6 = &regs.reg_ar6;
            argp.arg7 = &regs.reg_ar7;
    
            while(fgets(buff, 255, file)) {
                char *token = strtok(buff, " ");
                
                for(uint8_t i = 0; token != NULL; ++i) {
                    RemoveChars(token, 0xA);
                    inst[i] = (uint16_t) strtol(token, NULL, 16);
                    token = strtok(NULL, " ");
                }                

                printf("%hx %hx %hx %hx\n",inst[0],inst[1],inst[2],inst[3]);
                
                if(inst[0] != 0x22) {//imm
                    if(inst[1] == 0x0)  arg1 = &regs.reg_ar0; 
                    if(inst[1] == 0x1)  arg1 = &regs.reg_ar1; 
                    if(inst[1] == 0x2)  arg1 = &regs.reg_ar2; 
                    if(inst[1] == 0x3)  arg1 = &regs.reg_ar3; 
                    if(inst[1] == 0x4)  arg1 = &regs.reg_ar4; 
                    if(inst[1] == 0x5)  arg1 = &regs.reg_ar5; 
                    if(inst[1] == 0x6)  arg1 = &regs.reg_ar6; 
                    if(inst[1] == 0x7)  arg1 = &regs.reg_ar7; 
                    if(inst[1] == 0x8)  arg1 = &regs.reg_gp0; 
                    if(inst[1] == 0x9)  arg1 = &regs.reg_gp1; 
                    if(inst[1] == 0xA)  arg1 = &regs.reg_gp2; 
                    if(inst[1] == 0xB)  arg1 = &regs.reg_gp3; 
                    if(inst[1] == 0xC)  arg1 = &regs.reg_gp4; 
                    if(inst[1] == 0xD)  arg1 = &regs.reg_gp5; 
                    if(inst[1] == 0xE)  arg1 = &regs.reg_gp6; 
                    if(inst[1] == 0xF)  arg1 = &regs.reg_gp7; 
                    if(inst[1] == 0x10) arg1 = &regs.reg_mir; 
                    if(inst[1] == 0x11) arg1 = &regs.reg_rar; 
                    if(inst[1] == 0x12) arg1 = &regs.reg_cpr; 
                    if(inst[1] == 0x13) arg1 = &regs.reg_isc;
                } else arg1 = &inst[1];

                if(inst[2] == 0x0)  arg2 = &regs.reg_ar0; 
                if(inst[2] == 0x1)  arg2 = &regs.reg_ar1; 
                if(inst[2] == 0x2)  arg2 = &regs.reg_ar2; 
                if(inst[2] == 0x3)  arg2 = &regs.reg_ar3; 
                if(inst[2] == 0x4)  arg2 = &regs.reg_ar4; 
                if(inst[2] == 0x5)  arg2 = &regs.reg_ar5; 
                if(inst[2] == 0x6)  arg2 = &regs.reg_ar6; 
                if(inst[2] == 0x7)  arg2 = &regs.reg_ar7; 
                if(inst[2] == 0x8)  arg2 = &regs.reg_gp0; 
                if(inst[2] == 0x9)  arg2 = &regs.reg_gp1; 
                if(inst[2] == 0xA)  arg2 = &regs.reg_gp2; 
                if(inst[2] == 0xB)  arg2 = &regs.reg_gp3; 
                if(inst[2] == 0xC)  arg2 = &regs.reg_gp4; 
                if(inst[2] == 0xD)  arg2 = &regs.reg_gp5; 
                if(inst[2] == 0xE)  arg2 = &regs.reg_gp6; 
                if(inst[2] == 0xF)  arg2 = &regs.reg_gp7; 
                if(inst[2] == 0x10) arg2 = &regs.reg_mir; 
                if(inst[2] == 0x11) arg2 = &regs.reg_rar; 
                if(inst[2] == 0x12) arg2 = &regs.reg_cpr; 
                if(inst[2] == 0x13) arg2 = &regs.reg_isc;
                
                if(inst[3] == 0x1)  arg3 = &regs.reg_ar1; 
                if(inst[3] == 0x2)  arg3 = &regs.reg_ar2; 
                if(inst[3] == 0x3)  arg3 = &regs.reg_ar3; 
                if(inst[3] == 0x4)  arg3 = &regs.reg_ar4; 
                if(inst[3] == 0x5)  arg3 = &regs.reg_ar5; 
                if(inst[3] == 0x6)  arg3 = &regs.reg_ar6; 
                if(inst[3] == 0x7)  arg3 = &regs.reg_ar7; 
                if(inst[3] == 0x8)  arg3 = &regs.reg_gp0; 
                if(inst[3] == 0x9)  arg3 = &regs.reg_gp1; 
                if(inst[3] == 0xA)  arg3 = &regs.reg_gp2; 
                if(inst[3] == 0xB)  arg3 = &regs.reg_gp3; 
                if(inst[3] == 0xC)  arg3 = &regs.reg_gp4; 
                if(inst[3] == 0xD)  arg3 = &regs.reg_gp5; 
                if(inst[3] == 0xE)  arg3 = &regs.reg_gp6; 
                if(inst[3] == 0xF)  arg3 = &regs.reg_gp7; 
                if(inst[3] == 0x10) arg3 = &regs.reg_mir; 
                if(inst[3] == 0x11) arg3 = &regs.reg_rar; 
                if(inst[3] == 0x12) arg3 = &regs.reg_cpr; 
                if(inst[3] == 0x13) arg3 = &regs.reg_isc;
                 

                if(inst[0] == 0x0) inst_nop();
                else if(inst[0] == 0x1)  inst_mov(arg1,arg2);
                else if(inst[0] == 0x2)  inst_add(*arg1,*arg2,arg3);
                else if(inst[0] == 0x3)  inst_sub(*arg1,*arg2,arg3);
                else if(inst[0] == 0x4)  inst_mul(*arg1,*arg2,arg3);
                else if(inst[0] == 0x5)  inst_div(*arg1,*arg2,arg3);
                else if(inst[0] == 0x6)  inst_not(*arg1,arg2);
                else if(inst[0] == 0x7)  inst_and(*arg1,*arg2,arg3);
                else if(inst[0] == 0x8)  inst_nand(*arg1,*arg2,arg3);
                else if(inst[0] == 0x9)  inst_or(*arg1,*arg2,arg3);
                else if(inst[0] == 0xA)  inst_nor(*arg1,*arg2,arg3);
                else if(inst[0] == 0xB)  inst_xor(*arg1,*arg2,arg3);
                else if(inst[0] == 0xC)  inst_nxor(*arg1,*arg2,arg3);
                else if(inst[0] == 0xD)  inst_shl(*arg1,*arg2,arg3);
                else if(inst[0] == 0xE)  inst_shr(*arg1,*arg2,arg3);
                //else if(inst[0] == 0xF)  inst_mov(inst[1],inst[2]);
                //else if(inst[0] == 0x10) inst_mov(inst[1],inst[2]);
                //else if(inst[0] == 0x11) inst_mov(inst[1],inst[2]);
                //else if(inst[0] == 0x12) inst_mov(inst[1],inst[2]);
                //else if(inst[0] == 0x13) inst_mov(inst[1],inst[2]);
                //else if(inst[0] == 0x14) inst_mov(inst[1],inst[2]);
                //else if(inst[0] == 0x15) inst_mov(inst[1],inst[2]);
                //else if(inst[0] == 0x16) inst_mov(inst[1],inst[2]);
                //else if(inst[0] == 0x17) inst_mov(inst[1],inst[2]);
                //else if(inst[0] == 0x18) inst_mov(inst[1],inst[2]);
                //else if(inst[0] == 0x19) inst_mov(inst[1],inst[2]);
                //else if(inst[0] == 0x1A) inst_mov(inst[1],inst[2]);
                //else if(inst[0] == 0x1B) inst_mov(inst[1],inst[2]);
                //else if(inst[0] == 0x1C) inst_mov(inst[1],inst[2]);
                //else if(inst[0] == 0x1D) inst_mov(inst[1],inst[2]);
                //else if(inst[0] == 0x1E) inst_mov(inst[1],inst[2]);
                //else if(inst[0] == 0x1F) inst_mov(inst[1],inst[2]);
                else if(inst[0] == 0x20) inst_imm(*arg1,arg2);
                else if(inst[0] == 0x21) inst_hrdcall(&argp);
            }

            fclose(file);
        }
    }
    return 0;
}

uint8_t checkend(char* string){
    uint8_t len = (uint8_t) strlen(string); 
    if(len < 4) return 0;
    char *dot = strrchr(string, '.');
    if(strcmp(".gas", dot) == 0) return 1;
    if(strcmp(".hxd", dot) == 0) return 2;
    if(strcmp(".hx", dot) == 0)  return 2;
    return 0;
}