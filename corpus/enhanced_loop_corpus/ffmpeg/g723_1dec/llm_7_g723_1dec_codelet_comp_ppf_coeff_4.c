#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t scale;
extern int i;
extern int energy[5];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int prev_index;
    for (i = 0; i < 5; i++) {
        prev_index = (i == 0) ? 0 : i - 1;
        energy[i] = ((energy[prev_index] << scale) >> 16);
    }
}
