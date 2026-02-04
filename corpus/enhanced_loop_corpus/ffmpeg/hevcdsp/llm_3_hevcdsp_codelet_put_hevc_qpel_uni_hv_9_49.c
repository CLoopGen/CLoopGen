#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int height;
extern int width;
extern int x;
extern int y;
extern  int8_t *filter;
extern uint16_t *src;
extern ptrdiff_t srcstride;
extern int16_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
ptrdiff_t vec_stride = srcstride / sizeof(uint16_t);
for (y = 0; y < height + 7; y++) {
    uint16_t* src_row = (uint16_t*)((char*)src + y * srcstride);
    for (x = 0; x < width; x += 4) {
        for (int v = 0; v < 4 && (x + v) < width; v++) {
            int center = x + v;
            tmp[center] = (int16_t)(
                filter[0] * src_row[center - 3] +
                filter[1] * src_row[center - 2] +
                filter[2] * src_row[center - 1] +
                filter[3] * src_row[center] +
                filter[4] * src_row[center + 1] +
                filter[5] * src_row[center + 2] +
                filter[6] * src_row[center + 3] +
                filter[7] * src_row[center + 4]
            ) >> 1;
        }
    }
    tmp += 64;
}
}
