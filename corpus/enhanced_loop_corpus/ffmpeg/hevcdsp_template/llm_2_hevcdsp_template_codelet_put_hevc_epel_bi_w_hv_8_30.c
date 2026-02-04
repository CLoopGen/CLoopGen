#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int height;
extern int width;
extern int x;
extern int y;
extern uint8_t *src;
extern ptrdiff_t srcstride;
extern  int8_t *filter;
extern int16_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with array indexing unrolled for spatial locality
    int offset = 0;
    for (y = 0; y < height + 3; y++) {
        uint8_t *src_row = src + y * srcstride;
        int16_t *tmp_row = tmp + y * 64;
        for (x = 0; x < width; x += 4) {
            // Unroll to access four elements consecutively for better cache utilization
            if (x + 0 < width) tmp_row[x + 0] = (int16_t)((filter[0] * src_row[x - 1 + 0] + filter[1] * src_row[x + 0] + 
                                        filter[2] * src_row[x + 1 + 0] + filter[3] * src_row[x + 2]) >> 0);
            if (x + 1 < width) tmp_row[x + 1] = (int16_t)((filter[0] * src_row[x - 1 + 1] + filter[1] * src_row[x + 1] + 
                                        filter[2] * src_row[x + 1 + 1] + filter[3] * src_row[x + 3]) >> 0);
            if (x + 2 < width) tmp_row[x + 2] = (int16_t)((filter[0] * src_row[x - 1 + 2] + filter[1] * src_row[x + 2] + 
                                        filter[2] * src_row[x + 1 + 2] + filter[3] * src_row[x + 4]) >> 0);
            if (x + 3 < width) tmp_row[x + 3] = (int16_t)((filter[0] * src_row[x - 1 + 3] + filter[1] * src_row[x + 3] + 
                                        filter[2] * src_row[x + 1 + 3] + filter[3] * src_row[x + 5]) >> 0);
        }
    }
}
