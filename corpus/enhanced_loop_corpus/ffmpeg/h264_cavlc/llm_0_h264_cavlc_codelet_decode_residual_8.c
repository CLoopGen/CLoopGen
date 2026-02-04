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
    for (j = 0; j < total_coeff; j++) {
        for (i = j; i < total_coeff && j == i; i++) {
            scantable--;
            ((int16_t *)block)[*scantable] = ((int)(level[i] * qmul[*scantable] + 32)) >> 6;
        }
    }
}
