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
    int j;
    for (j = 0; j < total_coeff && i + j < total_coeff; j++) {
        scantable--;
        ((int16_t *)block)[*scantable] = level[i + j];
    }
    i += j;
}
