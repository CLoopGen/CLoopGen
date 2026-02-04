#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t dst[64];
extern  int16_t src[64];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 64; i += 2) {
        int index1 = (i >> 3) | ((i << 3) & 56);
        int index2 = ((i+1) >> 3) | (((i+1) << 3) & 56);
        dst[index1] = src[i];
        if (i + 1 < 64) dst[index2] = src[i+1];
    }
}
