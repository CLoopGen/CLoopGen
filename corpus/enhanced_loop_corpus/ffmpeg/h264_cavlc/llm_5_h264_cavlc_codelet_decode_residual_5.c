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
    int j = 0;
    for (; i < total_coeff && j < total_coeff; i++, j++) {
        if (level[i] == 0) continue;
        scantable--;
        ((int32_t *)block)[*scantable] = level[i];
    }
}
