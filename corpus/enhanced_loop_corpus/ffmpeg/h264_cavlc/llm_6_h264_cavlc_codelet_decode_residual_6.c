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
    int temp;
    for (; i < total_coeff; i++) {
        scantable--;
        temp = level[i] * qmul[*scantable];
        ((int32_t *)block)[*scantable] = (temp + 32) >> 6;
    }
}
