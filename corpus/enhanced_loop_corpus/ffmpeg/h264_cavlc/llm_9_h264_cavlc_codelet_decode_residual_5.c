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
        scantable--;
        ((int32_t *)block)[*scantable] = level[i];
        if (i + 1 < total_coeff) {
            scantable--;
            ((int32_t *)block)[*scantable] = level[i + 1];
        }
    }
}
