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
    for (y = 0; y < h + 6 - 1; y++) {
        for (int unroll_factor = 0; unroll_factor < 8; unroll_factor += 4) {
            for (x = unroll_factor; x < unroll_factor + 4 && x < 8; x++) {
                tmp[x] = cm[(filter[2] * src[x + 0 * 1] - filter[1] * src[x - 1 * 1] + filter[3] * src[x + 1 * 1] - filter[4] * src[x + 2 * 1] + 64) >> 7];
            }
        }
        tmp += 8;
        src += srcstride;
    }
}
