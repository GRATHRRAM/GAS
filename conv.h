#ifndef CONV_H
#define CONV_H

#include <stdint.h>

#define conv_bin 0 //binary
#define conv_dec 1 //decimal
#define conv_hxd 2 //hexdecimal

void conv_asm_to_hex(const char* File_name);
void RemoveChars(char *s, char c);

#endif //!CONV_H