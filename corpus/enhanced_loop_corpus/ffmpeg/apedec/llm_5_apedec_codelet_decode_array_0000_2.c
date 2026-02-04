#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *out;
extern int blockstodecode;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < blockstodecode; i++) {
        if (i % 2 == 0 || out[i] < 0) {
            out[i] = ((out[i] >> 1) ^ ((out[i] & 1) - 1)) + 1;
        } else {
            out[i] = (out[i] >> 1) + 1;
        }
    }
}
