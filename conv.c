#define CONV_C

#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define conv_bin 0 //binary
#define conv_dec 1 //decimal
#define conv_hxd 2 //hexdecimal

#define buffsize 255

void RemoveChars(char *s, char c) {
    int writer = 0, reader = 0;

    while (s[reader]) {
        if (s[reader]!=c) {   
            s[writer++] = s[reader];
        }
        reader++;       
    }
    s[writer]=0;
}

void conv_asm(const char* File_name, uint8_t mode) {
    FILE *file;
    FILE *filew;
    char buff[buffsize];
    file = fopen(File_name, "r");
    filew = fopen("grah16.hxd", "w");
    
    while(fgets(buff, buffsize, file)) {
        if(strcmp(buff, "\n") != 0) {
            char *token = strtok(buff, " ");
            RemoveChars(token,',');
            while( token != NULL ) {
                if(strlen(token) > 1) if(token[0] == ';') break;
                //if(strcmp(token, "\n") != 0) fprintf(filew,"%s ", token);
                if(strcmp(token, "\n") != 0) {
                    if(strcmp(token, "nop")  == 0) fprintf(filew,"00");
                    else if(strcmp(token, "mov")  == 0) fprintf(filew,"01");
                    else if(strcmp(token, "add")  == 0) fprintf(filew,"02");
                    else if(strcmp(token, "sub")  == 0) fprintf(filew,"03");
                    else if(strcmp(token, "mul")  == 0) fprintf(filew,"04");
                    else if(strcmp(token, "div")  == 0) fprintf(filew,"05");
                    else if(strcmp(token, "not")  == 0) fprintf(filew,"06");
                    else if(strcmp(token, "and")  == 0) fprintf(filew,"07");
                    else if(strcmp(token, "nand") == 0) fprintf(filew,"08");
                    else if(strcmp(token, "or")   == 0) fprintf(filew,"09");
                    else if(strcmp(token, "nor")  == 0) fprintf(filew,"0A");
                    else if(strcmp(token, "xor")  == 0) fprintf(filew,"0B");
                    else if(strcmp(token, "nxor") == 0) fprintf(filew,"0C");
                    else if(strcmp(token, "shl")  == 0) fprintf(filew,"0D");
                    else if(strcmp(token, "shr")  == 0) fprintf(filew,"0E");
                    else if(strcmp(token, "jmp")  == 0) fprintf(filew,"0F");
                    else if(strcmp(token, "jz")   == 0) fprintf(filew,"10");
                    else if(strcmp(token, "jnz")  == 0) fprintf(filew,"11");
                    else if(strcmp(token, "equ")  == 0) fprintf(filew,"12");
                    else if(strcmp(token, "neq")  == 0) fprintf(filew,"13");
                    else if(strcmp(token, "grt")  == 0) fprintf(filew,"14");
                    else if(strcmp(token, "grq")  == 0) fprintf(filew,"15");
                    else if(strcmp(token, "les")  == 0) fprintf(filew,"16");
                    else if(strcmp(token, "leq")  == 0) fprintf(filew,"17");
                    else if(strcmp(token, "grts") == 0) fprintf(filew,"18");
                    else if(strcmp(token, "grqs") == 0) fprintf(filew,"19");
                    else if(strcmp(token, "less") == 0) fprintf(filew,"1A");
                    else if(strcmp(token, "leqs") == 0) fprintf(filew,"1B");
                    else if(strcmp(token, "call") == 0) fprintf(filew,"1C");
                    else if(strcmp(token, "ret")  == 0) fprintf(filew,"1D");
                    else if(strcmp(token, "push") == 0) fprintf(filew,"1E");
                    else if(strcmp(token, "pop")  == 0) fprintf(filew,"1F");
                    else if(strcmp(token, "qin")  == 0) fprintf(filew,"20");
                    else if(strcmp(token, "qout") == 0) fprintf(filew,"21");
                    else if(strcmp(token, "imm")  == 0) fprintf(filew,"22");
                    else if(strcmp(token,"hrdcall")==0) fprintf(filew,"23");
                    else if(strcmp(token, "ra8")  == 0) fprintf(filew,"24");
                    else if(strcmp(token, "ra16") == 0) fprintf(filew,"25");

                    else if(strcmp(token, "ar0")  == 0) fprintf(filew,"00");
                    else if(strcmp(token, "ar1")  == 0) fprintf(filew,"01");
                    else if(strcmp(token, "ar2")  == 0) fprintf(filew,"02");
                    else if(strcmp(token, "ar3")  == 0) fprintf(filew,"03");
                    else if(strcmp(token, "ar4")  == 0) fprintf(filew,"04");
                    else if(strcmp(token, "ar5")  == 0) fprintf(filew,"05");
                    else if(strcmp(token, "ar6")  == 0) fprintf(filew,"06");
                    else if(strcmp(token, "ar7")  == 0) fprintf(filew,"07");
                    else if(strcmp(token, "gp0")  == 0) fprintf(filew,"08");
                    else if(strcmp(token, "gp1")  == 0) fprintf(filew,"09");
                    else if(strcmp(token, "gp2")  == 0) fprintf(filew,"0A");
                    else if(strcmp(token, "gp3")  == 0) fprintf(filew,"0B");
                    else if(strcmp(token, "gp4")  == 0) fprintf(filew,"0C");
                    else if(strcmp(token, "gp5")  == 0) fprintf(filew,"0D");
                    else if(strcmp(token, "gp6")  == 0) fprintf(filew,"0E");
                    else if(strcmp(token, "gp7")  == 0) fprintf(filew,"0F");
                    else if(strcmp(token, "mir")  == 0) fprintf(filew,"10");
                    else if(strcmp(token, "rar")  == 0) fprintf(filew,"11");
                }
                token = strtok(NULL, " ");
            }
            fprintf(filew,"\n");
        }
    }
    fclose(file);
}

void conv_mode(const char* File_name, uint8_t mode_in, uint8_t mode_out) {
    return;
}
