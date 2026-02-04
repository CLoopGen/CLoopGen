#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t block[64];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < 64; i++) {
        block[i] = (block[i] + block[i-1]) >> 3;
    }
    if (64 > 0) {
        block[0] >>= 3;
    }
}
