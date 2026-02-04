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
    uint8_t temp_sum[8];
    for (x = 0; x < 8; x++)
        temp_sum[x] = (src[(8) + 7 - y] * y + src[(8 + 8 + 1) + x] * (8 - y) + 4) >> 3;
    for (x = 0; x < 8; x++)
        dst[x] = temp_sum[x];
    dst += stride;
}
}
