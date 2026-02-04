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
    for (; i < total_coeff && scantable > ((uint8_t *)0); i++) {
        scantable--;
        int coeff = level[i];
        if (coeff != 0) {
            ((int16_t *)block)[*scantable] = ((int)(coeff * qmul[*scantable] + 32)) >> 6;
        }
    }
}
