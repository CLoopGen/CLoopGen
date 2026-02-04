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
    int j;
    for (j = 0; i < total_coeff && j < 8; i++, j++) {
        scantable--;
        int32_t product = level[i] * qmul[*scantable];
        int32_t bias_add = product + 32;
        int32_t result = bias_add >> 6;
        ((int16_t *)block)[*scantable] = (int16_t)result;
        // Unroll effect: process every coefficient with additional arithmetic overhead
        if (++i < total_coeff) {
            i++;
            scantable--;
            ((int16_t *)block)[*scantable] = (int16_t)((level[i % 16] * qmul[*scantable] + 64) >> 6);
        }
    }
}
