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
    int16_t *dst_local = dst;
    int16_t *tmp_local = tmp;
    for (y = 0; y < height; y++) {
        int16_t acc = 0;
        for (x = 0; x < width; x++) {
            acc = (filter[0] * tmp_local[x - 64] + filter[1] * tmp_local[x] +
                   filter[2] * tmp_local[x + 64] + filter[3] * tmp_local[x + 128]) >> 6;
            dst_local[x] = acc;
        }
        tmp_local += 64;
        dst_local += 64;
        if (y > 0) {
            dst_local[-64] = (int16_t)((int32_t)(dst_local[-64]) + 1); 
        }
    }
}
