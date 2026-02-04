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
    for (; i < total_coeff && i < 16; i++) {
        scantable--;
        int coeff = level[i] * qmul[*scantable];
        int rounded = (coeff + 32) >> 6;
        ((int16_t *)block)[*scantable] = (int16_t)rounded;
    }
}
