#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *out;
extern ptrdiff_t pitch;
extern int blk_size;
extern int x;
extern int y;
extern int16_t dc_coeff;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int16_t temp[blk_size]; // Local buffer to remove immediate write dependencies
    for (int i = 0; i < blk_size; i++)
        temp[i] = dc_coeff;

    for (y = 0; y < blk_size; y++) {
        for (x = 0; x < blk_size; x++) {
            out[x] = temp[x]; // Decouple computation from storage: no intra-loop WAW or WAR
        }
        out += pitch; // Advance output pointer after full row write
    }
}
