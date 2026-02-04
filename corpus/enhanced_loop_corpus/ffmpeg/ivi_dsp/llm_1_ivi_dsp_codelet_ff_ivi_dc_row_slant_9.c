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
    int outer = blk_size / 2;
    int inner = 2;
    for (int i = 0; i < outer; i++)
        for (int j = 0; j < inner; j++)
            out[i * inner + j] = dc_coeff;
    if (blk_size % 2)
        out[blk_size - 1] = dc_coeff;
}
