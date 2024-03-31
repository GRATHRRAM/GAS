#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "conv.h"
#include "grah16.h"

uint8_t checkend(char* string);

int main(int argc, char **argv) {
    if(argc > 0) {
        uint8_t info = checkend(argv[1]);
        if(info == 1) conv_asm_to_hex(argv[1]);
        else if(info == 2){
            FILE *file;
            char buff[255];
            uint16_t inst[4];
            file = fopen(argv[1], "r");//segv ¯\_(ツ)_/¯
    
            while(fgets(buff, 255, file)) {
                char *token = strtok(buff, " ");
                
                for(uint8_t i = 0; token != NULL; ++i) {
                    inst[i] = (uint16_t) strtol(strtok(NULL, " "), NULL, 16);
                }                

                printf("%hx %hx %hx %hx\n",inst[0],inst[1],inst[2],inst[3]);
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