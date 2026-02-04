#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *input;
extern int16_t temp_value[8];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < 1; ++j)
        for (int i = 0; i < 8; ++i)
            temp_value[i] = (46341 * input[i << 3] + (8 << 16)) >> 20;
}
