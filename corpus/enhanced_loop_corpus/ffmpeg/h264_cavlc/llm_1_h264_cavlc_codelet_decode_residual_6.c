#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *block;
extern  uint8_t *scantable;
extern  uint32_t *qmul;
extern int level[16];
extern int total_coeff;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int outer_i;
    for (outer_i = i; outer_i < total_coeff; outer_i++) {
        for (; i <= outer_i && i < total_coeff; i++) {
            scantable--;
            ((int32_t *)block)[*scantable] = ((int)(level[i] * qmul[*scantable] + 32)) >> 6;
        }
    }
}
