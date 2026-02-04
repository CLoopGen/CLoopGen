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
    int16_t *dst_base = dst;
    int16_t *tmp_base = tmp;
    for (y = 0; y < height; y++) {
        int offset = y * 64;
        for (x = 0; x < width; x++) {
            int idx = offset + x;
            int16_t sum = 0;
            sum += filter[0] * tmp_base[idx - 3 * 64];
            sum += filter[1] * tmp_base[idx - 2 * 64];
            sum += filter[2] * tmp_base[idx - 64];
            sum += filter[3] * tmp_base[idx];
            sum += filter[4] * tmp_base[idx + 64];
            sum += filter[5] * tmp_base[idx + 2 * 64];
            sum += filter[6] * tmp_base[idx + 3 * 64];
            sum += filter[7] * tmp_base[idx + 4 * 64];
            dst_base[idx] = sum >> 6;
        }
    }
}
