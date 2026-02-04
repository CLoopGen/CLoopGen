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
    for (y = 0; y < height; y++) {
        int16_t *tmp_offset = tmp + y * 64;
        int16_t *dst_offset = dst + y * 64;
        for (x = 0; x < width; x++) {
            int32_t sum = 0;
            sum += filter[0] * tmp_offset[x - 3 * 64];
            sum += filter[1] * tmp_offset[x - 2 * 64];
            sum += filter[2] * tmp_offset[x - 64];
            sum += filter[3] * tmp_offset[x];
            sum += filter[4] * tmp_offset[x + 64];
            sum += filter[5] * tmp_offset[x + 2 * 64];
            sum += filter[6] * tmp_offset[x + 3 * 64];
            sum += filter[7] * tmp_offset[x + 4 * 64];
            dst_offset[x] = sum >> 6;
        }
    }
}
