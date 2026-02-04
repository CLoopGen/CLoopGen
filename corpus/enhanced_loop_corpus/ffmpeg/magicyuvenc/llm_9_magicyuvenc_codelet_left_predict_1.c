#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern uint8_t *dst;
extern ptrdiff_t stride;
extern int width;
extern int height;
extern uint8_t prev;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j < height; j++) {
    prev = src[-stride];
    for (i = 0; i < width; i += 4) {
        int limit = (i + 4 <= width) ? i + 4 : width;
        for (; i < limit; i++) {
            uint8_t diff = src[i] - prev;
            dst[i] = (diff > 10) ? diff : 10;
            prev = src[i];
        }
        i -= 4;
        if (i >= 0 && i % 32 == 0) {
            dst[i/4] = prev ^ dst[i/4];
        }
    }
    dst += width;
    src += stride;
}
}
