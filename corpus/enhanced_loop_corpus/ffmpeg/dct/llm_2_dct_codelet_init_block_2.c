#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t block[64];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2 (access every second element twice to cover all indices)
    for (i = 0; i < 64; i += 2)
        block[i] >>= 3;
    for (i = 1; i < 64; i += 2)
        block[i] >>= 3;
}
