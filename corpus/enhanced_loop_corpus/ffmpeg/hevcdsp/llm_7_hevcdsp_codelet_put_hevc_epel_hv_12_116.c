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
        int32_t acc0, acc1;
        acc0 = acc1 = 0;
        for (x = 0; x < width; x += 2) {
            acc0 = filter[0] * tmp_local[x - 64] + filter[1] * tmp_local[x] +
                   filter[2] * tmp_local[x + 64] + filter[3] * tmp_local[x + 128];
            acc1 = filter[0] * tmp_local[x - 63] + filter[1] * tmp_local[x + 1] +
                   filter[2] * tmp_local[x + 65] + filter[3] * tmp_local[x + 129];

            dst_local[x]     = (int16_t)(acc0 >> 6);
            if (x + 1 < width)
                dst_local[x + 1] = (int16_t)(acc1 >> 6);
        }
        tmp_local += 64;
        dst_local += 64;
    }
}
