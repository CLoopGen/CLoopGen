#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *input;
extern int16_t temp_value[8];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int16_t local_temp[8];
    for (int i = 0; i < 8; ++i)
        local_temp[i] = (46341 * input[i << 3] + (8 << 16)) >> 20;
    for (int i = 0; i < 8; ++i)
        temp_value[i] = local_temp[i];
}
