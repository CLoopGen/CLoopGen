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
for (y = 0; y < 8; ++y) {
    for (int block = 0; block < 8; block += 4) {
        x = block;
        if (x < 8) dst[x] = src[14 - ((x + y) > 6 ? 6 : (x + y))];
        x = block + 1;
        if (x < 8) dst[x] = src[14 - ((x + y) > 6 ? 6 : (x + y))];
        x = block + 2;
        if (x < 8) dst[x] = src[14 - ((x + y) > 6 ? 6 : (x + y))];
        x = block + 3;
        if (x < 8) dst[x] = src[14 - ((x + y) > 6 ? 6 : (x + y))];
    }
    dst += stride;
}
}
