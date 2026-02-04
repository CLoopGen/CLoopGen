#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *out;
extern int blk_size;
extern int x;
extern int16_t dc_coeff;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < blk_size; i++)
        for (int j = 0; j < 1; j++)
            out[i] = dc_coeff;
}
