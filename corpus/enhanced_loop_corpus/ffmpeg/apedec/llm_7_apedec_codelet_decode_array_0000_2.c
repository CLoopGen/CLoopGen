#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *out;
extern int blockstodecode;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (blockstodecode > 0) {
        out[0] = ((out[0] >> 1) ^ ((out[0] & 1) - 1)) + 1;
        for (i = 1; i < blockstodecode; i++) {
            out[i] = ((out[i] >> 1) ^ ((out[i] & 1) - 1)) + 1 + (out[i-1] & 1);
        }
    }
}
