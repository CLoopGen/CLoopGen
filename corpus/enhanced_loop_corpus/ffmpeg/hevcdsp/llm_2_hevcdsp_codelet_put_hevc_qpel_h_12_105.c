#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern int height;
extern int width;
extern int x;
extern int y;
extern uint16_t *src;
extern ptrdiff_t srcstride;
extern  int8_t *filter;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = 0; y < height; y++) {
        int16_t *dst_row = dst + y * 64;
        const uint16_t *src_row = src + y * srcstride;
        for (x = 0; x < width; x++) {
            int32_t sum = 0;
            const int8_t *f = filter;
            sum += f[0] * src_row[x - 3];
            sum += f[1] * src_row[x - 2];
            sum += f[2] * src_row[x - 1];
            sum += f[3] * src_row[x];
            sum += f[4] * src_row[x + 1];
            sum += f[5] * src_row[x + 2];
            sum += f[6] * src_row[x + 3];
            sum += f[7] * src_row[x + 4];
            dst_row[x] = sum >> 4;
        }
    }
}
