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
    for (x = 0; x < 8; x++) {
        int index1 = (8 + 8) - 1 + x - 2 * y;
        int index2 = (8 + 8) + x - 2 * y;
        int condition = x - 2 * y > 0;
        dst[x] = condition ? ((src[index1] + src[index2] + 1) >> 1) : src[(8) + 8 - y + (x >> 1)];
    }
    dst += stride;
}
}
