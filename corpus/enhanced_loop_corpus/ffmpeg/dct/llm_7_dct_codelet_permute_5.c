#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t dst[64];
extern  int16_t src[64];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int16_t local_dst[64];
    for (i = 0; i < 64; i++) {
        local_dst[(i >> 3) | ((i << 3) & 56)] = src[i];
    }
    for (i = 0; i < 64; i++) {
        dst[i] = local_dst[i];
    }
}
