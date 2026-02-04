#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *input;
extern int16_t temp_value[8];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < 8; ++i) {
        int index = i << 3;
        if (index < 64) {
            temp_value[i] = (46341 * input[index] + (8 << 16)) >> 20;
        }
    }
}
