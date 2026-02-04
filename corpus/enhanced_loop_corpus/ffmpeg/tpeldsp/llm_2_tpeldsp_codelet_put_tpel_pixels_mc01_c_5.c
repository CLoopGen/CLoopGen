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
for (i = 0; i < height; i++) {
    uint8_t *src_row = src + i * stride;
    uint8_t *dst_row = dst + i * stride;
    for (j = 0; j < width; j++) {
        dst_row[j] = ((2 * src_row[j] + src_row[j + stride] + 1) * 683) >> 11;
    }
}
}
