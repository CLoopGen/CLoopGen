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
    for (x = 0; x < 8; x += 2) {
        int idx1 = (2 * y + x + 2);
        int idx2 = (2 * y + x + 3);
        idx1 = idx1 > 15 ? 15 : idx1;
        idx2 = idx2 > 15 ? 15 : idx2;
        dst[x]     = src[17 + idx1];
        if (x + 1 < 8)
            dst[x + 1] = src[17 + idx2];
    }
    dst += stride;
}
}
