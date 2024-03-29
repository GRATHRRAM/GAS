#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "conv.h"
#include "grah16.h"

uint8_t checkend(char* string);

int main(int argc, char **argv) {
    if(argc > 0) {
        uint8_t info = checkend(argv[1]);
        if(info == 1) conv_asm(argv[1], conv_hxd);
        else if(info == 2){
            FILE *file;
            char buff[255];
            uint16_t inst,arg1,arg2,arg3;
            file = fopen(argv[1], "r");
                
            while(fgets(buff, 255, file)) {
                char *token = strtok(buff, " ");

                printf("%d ");
                token = strtok(NULL, " ");
            }
        }
    }
    return 0;
}

uint8_t checkend(char* string){
    uint8_t len = (uint8_t) strlen(string); 
    if(len < 5) return 0;
    if(string[len] == 's' && string[len-1] == 'a' && string[len-2] == 'g') return 1;
    if(string[len] == 'h' && string[len-1] == 'x' && string[len-2] == 'd') return 2;
    if(string[len] == 'h' && string[len-1] == 'x') return 2;
    return 0;
}