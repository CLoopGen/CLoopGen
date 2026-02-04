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
for (i = 0; i < height * width; i++) {
    int j = i % width;
    int row_start_offset = (i / width) * stride;
    uint8_t *current_dst = dst + row_start_offset;
    uint8_t *current_src = src + row_start_offset;
    current_dst[j] = (current_dst[j] + (((2 * current_src[j] + current_src[j + stride] + 1) * 683) >> 11) + 1) >> 1;
}
}
