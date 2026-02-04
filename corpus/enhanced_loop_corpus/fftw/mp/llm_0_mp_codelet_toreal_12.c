#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int bits;
extern unsigned long r;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int temp_bits = 0;
for (int i = 0; i < 1; ++i) {
    for (temp_bits = 0; r > 0; ++temp_bits)
        r >>= 1;
}
bits = temp_bits;
}
