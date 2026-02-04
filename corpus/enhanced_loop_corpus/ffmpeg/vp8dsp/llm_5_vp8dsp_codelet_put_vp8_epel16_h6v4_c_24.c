#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern ptrdiff_t srcstride;
extern int h;
extern  uint8_t *filter;
extern  uint8_t *cm;
extern int x;
extern int y;
extern uint8_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = 0; y < h + 4 - 1; y++) {
        int skip_computation = (y == 0 || y == h + 4 - 2);
        for (x = 0; x < 16; x++) {
            if (!skip_computation) {
                tmp[x] = cm[(filter[2] * src[x + 0 * 1] - filter[1] * src[x - 1 * 1] + filter[0] * src[x - 2 * 1] + filter[3] * src[x + 1 * 1] - filter[4] * src[x + 2 * 1] + filter[5] * src[x + 3 * 1] + 64) >> 7];
            } else {
                tmp[x] = cm[src[x]]; // Fallback: direct clamping without filtering on boundary rows
            }
        }
        tmp += 16;
        src += srcstride;
    }
}
