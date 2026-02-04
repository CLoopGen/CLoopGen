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
        for (x = 0; x < width; x++) {
            int32_t sum = 0;
            sum += filter[0] * tmp_local[x - 64];
            sum += filter[1] * tmp_local[x];
            sum += filter[2] * tmp_local[x + 64];
            sum += filter[3] * tmp_local[x + 128];
            dst_local[x] = (int16_t)(sum >> 6);
        }
        tmp_local += 64;
        dst_local += 64;
    }
}
