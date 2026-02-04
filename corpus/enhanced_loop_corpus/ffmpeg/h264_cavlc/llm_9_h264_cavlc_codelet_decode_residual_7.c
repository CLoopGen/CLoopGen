#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *block;
extern  uint8_t *scantable;
extern int level[16];
extern int total_coeff;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int stride = 2;
    for (; i < total_coeff; i += stride) {
        scantable -= stride;
        int16_t val = level[i];
        ((int16_t *)block)[*(scantable)] = val;
        if (i + 1 < total_coeff) {
            ((int16_t *)block)[*(scantable + 1)] = level[i + 1];
        }
    }
}
