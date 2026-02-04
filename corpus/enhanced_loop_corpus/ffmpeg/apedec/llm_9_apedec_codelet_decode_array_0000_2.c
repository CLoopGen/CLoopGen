#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *out;
extern int blockstodecode;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < blockstodecode * 2; i++) {
        int32_t temp = out[i % blockstodecode];
        temp = ((temp >> 2) ^ ((temp & 3) - 1)) + 2;
        out[i % blockstodecode] = temp ^ out[i % blockstodecode];
    }
}
