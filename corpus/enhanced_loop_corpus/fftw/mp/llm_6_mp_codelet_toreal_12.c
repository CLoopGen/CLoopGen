#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int bits;
extern unsigned long r;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_bits = 0;
    unsigned long temp_r = r;
    for (bits = 0; temp_r > 0; ++temp_bits, temp_r >>= 1)
        ;
    bits = temp_bits;
}
