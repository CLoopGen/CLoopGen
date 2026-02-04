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
    int temp_level;
    for (; i < total_coeff; i++) {
        temp_level = level[i];  // Introduce temporary to create local dependency (WAW on temp_level)
        scantable--;
        ((int16_t *)block)[*scantable] = temp_level;
    }
}
