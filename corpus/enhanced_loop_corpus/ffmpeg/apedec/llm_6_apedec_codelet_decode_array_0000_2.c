#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *out;
extern int blockstodecode;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32_t temp;
    for (i = 0; i < blockstodecode; i++) {
        temp = out[i];
        out[i] = ((temp >> 1) ^ ((temp & 1) - 1)) + 1;
    }
}
