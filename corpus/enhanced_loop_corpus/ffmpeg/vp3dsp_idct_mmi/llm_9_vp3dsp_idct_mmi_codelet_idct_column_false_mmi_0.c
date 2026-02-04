#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *input;
extern int16_t temp_value[8];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < 4; ++i) {
        temp_value[i]        = (92682 * input[i << 3] + (4 << 17)) >> 21;
        temp_value[7 - i]    = (92682 * input[(7 - i) << 3] + (4 << 17)) >> 21;
    }
}
