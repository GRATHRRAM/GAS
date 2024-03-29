#include <stdio.h>
#include <stdlib.h>

#include "conv.h"
#include "grah16.h"

int main(int argc, char **argv) {
    if(argc > 0) conv_asm(argv[1], conv_hxd);
    else conv_asm("test.gas", conv_hxd);
    return 0;
}
