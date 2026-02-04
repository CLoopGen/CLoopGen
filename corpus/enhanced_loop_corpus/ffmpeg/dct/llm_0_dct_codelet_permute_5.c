#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t dst[64];
extern  int16_t src[64];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int i_outer, i_inner;
for (i_outer = 0; i_outer < 8; i_outer++) {
    for (i_inner = 0; i_inner < 8; i_inner++) {
        i = (i_outer << 3) | i_inner;
        dst[(i >> 3) | ((i << 3) & 56)] = src[i];
    }
}
}
