#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *out;
extern int blockstodecode;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < blockstodecode; j++) {
        for (i = 0; i < 1; i++) {
            out[j] = ((out[j] >> 1) ^ ((out[j] & 1) - 1)) + 1;
        }
    }
}
