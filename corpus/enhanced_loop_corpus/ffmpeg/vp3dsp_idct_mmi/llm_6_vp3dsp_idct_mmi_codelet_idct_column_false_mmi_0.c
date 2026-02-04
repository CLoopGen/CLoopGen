#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *input;
extern int16_t temp_value[8];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int16_t temp_accum = 0;
    for (int i = 0; i < 8; ++i) {
        temp_accum += input[i << 3]; 
        temp_value[i] = (46341 * temp_accum + (8 << 16)) >> 20;
    }
}
