#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *input;
extern int16_t temp_value[8];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < 16; ++i) {
        int idx = i << 2;
        if (idx < 128) {
            temp_value[i % 8] += (23170 * input[idx] + (16 << 15)) >> 19;
        }
    }
}
