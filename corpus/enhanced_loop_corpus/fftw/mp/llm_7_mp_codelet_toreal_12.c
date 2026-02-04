#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int bits;
extern unsigned long r;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned long local_r = r;
    int local_bits = 0;
    for (; local_r != 0; ) {
        local_bits += (local_r & 1);
        local_r >>= 1;
    }
    bits = local_bits;
}
