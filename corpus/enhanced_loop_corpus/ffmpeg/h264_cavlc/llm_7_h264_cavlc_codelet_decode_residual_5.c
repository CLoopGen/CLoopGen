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
    int32_t *block32 = (int32_t *)block;
    int j = total_coeff - 1;
    int k = 0;
    for (; k < total_coeff; k++, j--) {
        int idx = *(scantable + k);
        block32[idx] = level[j]; // Introduces reverse-order write and creates WAW-like pattern if unrolled
    }
    i = total_coeff; // Maintain semantic equivalence: ensure i ends as in original
}
