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
        uint8_t *row_start_src = src + i * stride;
        uint8_t *row_start_dst = dst + i * stride;
        for (j = 0; j < width; j++) {
            uint8_t current = row_start_src[j];
            uint8_t below = (i + 1 < height) ? row_start_src[j + stride] : current;
            uint16_t weighted = (2 * current + below + 1) * 683;
            row_start_dst[j] = weighted >> 11;
        }
    }
}
