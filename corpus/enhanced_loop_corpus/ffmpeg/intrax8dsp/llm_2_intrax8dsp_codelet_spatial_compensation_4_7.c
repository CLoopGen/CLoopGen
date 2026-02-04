#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern uint8_t *dst;
extern ptrdiff_t stride;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < 8; y++) {
    uint8_t *src_row1 = &src[(8 + 8 + 1) + y * 2 * 8];
    uint8_t *src_row2 = &src[(8 + 8 + 1 + 16) + y * 2 * 8];
    for (x = 0; x < 8; x++) {
        dst[x] = (src_row1[x] + src_row2[x] + 1) >> 1;
    }
    dst += stride;
}
}
