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
    // Variant 1: Consecutive memory access by pre-decrementing pointer and using offset indexing
    int16_t *block_ptr = (int16_t *)block;
    for (; i < total_coeff; i++) {
        uint8_t index = *(--scantable);
        block_ptr[index] = ((int)(level[i] * qmul[index] + 32)) >> 6;
    }
}
