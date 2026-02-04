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
    for (y = 0; y < height + 7; y++) {
        int16_t *temp_row = tmp;
        const uint16_t *src_row = src;
        for (x = 0; x < width; x++) {
            int32_t acc = 0;
            for (int k = 0; k < 8; k++) {
                acc += filter[k] * src_row[x + k - 3];
            }
            temp_row[x] = acc >> 1;
        }
        src += srcstride;
        tmp += 64;
    }
}
