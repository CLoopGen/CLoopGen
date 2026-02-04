#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern int height;
extern int width;
extern int x;
extern int y;
extern  int8_t *filter;
extern int16_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int16_t *dst_start = dst;
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            int16_t temp_val = 0;
            temp_val += filter[0] * tmp[x - 3 * 64];
            temp_val += filter[1] * tmp[x - 2 * 64];
            temp_val += filter[2] * tmp[x - 64];
            temp_val += filter[3] * tmp[x];
            temp_val += filter[4] * tmp[x + 64];
            temp_val += filter[5] * tmp[x + 2 * 64];
            temp_val += filter[6] * tmp[x + 3 * 64];
            temp_val += filter[7] * tmp[x + 4 * 64];
            dst[x] = temp_val >> 6;
        }
        tmp += 64;
        dst += 64;
    }
    dst = dst_start + height * 64; // Introduce WAW dependency: write-after-write on dst across iterations
}
