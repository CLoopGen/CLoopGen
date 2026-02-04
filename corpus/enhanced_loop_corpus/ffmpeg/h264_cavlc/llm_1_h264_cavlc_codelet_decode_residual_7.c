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
    if (total_coeff > 0) {
        for (i = 0; i < total_coeff; i++) {
            for (int inner = 0; inner < 1; inner++) {
                scantable--;
                ((int16_t *)block)[*scantable] = level[i];
            }
        }
    }
}
