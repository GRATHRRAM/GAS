#ifndef CONV_H
#define CONV_H

#include <stdint.h>

#define conv_bin 0 //binary
#define conv_dec 1 //decimal
#define conv_hxd 2 //hexdecimal

void conv_asm(char* File, uint8_t mode);
void conv_mode(char* File, uint8_t mode_in, uint8_t mode_out);

#endif //!CONV_H