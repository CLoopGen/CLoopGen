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
    for (int j = 0; j < total_coeff; j++) {
        for (i = j; i < j + 1 && i < total_coeff; i++) {
            scantable--;
            ((int16_t *)block)[*scantable] = level[i];
        }
    }
}
