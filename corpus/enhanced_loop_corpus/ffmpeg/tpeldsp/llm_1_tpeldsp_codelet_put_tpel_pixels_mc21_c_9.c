#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int stride;
extern int width;
extern int height;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < height * stride; i += stride) {
    uint8_t *src_row = src + i;
    uint8_t *dst_row = dst + i;
    for (j = 0; j < width; j++) {
        dst_row[j] = ((3 * src_row[j] + 4 * src_row[j + 1] + 2 * src_row[j + stride] + 3 * src_row[j + stride + 1] + 6) * 2731) >> 15;
    }
}
}
