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
    if (y % 2 == 0) {
        for (x = 0; x < 8; x++) {
            int val = filter[2] * src[x + 0 * 1] - filter[1] * src[x - 1 * 1] +
                      filter[3] * src[x + 1 * 1] - filter[4] * src[x + 2 * 1] + 64;
            tmp[x] = cm[val >> 7];
        }
    } else {
        for (x = 0; x < 8; x++) {
            tmp[x] = cm[(filter[2] * src[x] - filter[1] * src[x - 1] +
                         filter[3] * src[x + 1] - filter[4] * src[x + 2] + 64) >> 7];
        }
    }
    tmp += 8;
    src += srcstride;
}
}
