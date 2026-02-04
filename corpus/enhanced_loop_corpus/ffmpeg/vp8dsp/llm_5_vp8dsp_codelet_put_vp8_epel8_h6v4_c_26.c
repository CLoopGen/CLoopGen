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
        int skip_computation = (y == 2 || y == h);
        if (!skip_computation) {
            for (x = 0; x < 8; x++) {
                int index = x + 0 * 1;
                int val = filter[2] * src[index] -
                          (x >= 1 ? filter[1] * src[index - 1] : 0) +
                          (x >= 2 ? filter[0] * src[index - 2] : 0) +
                          (x + 1 < 8 ? filter[3] * src[index + 1] : 0) -
                          (x + 2 < 8 ? filter[4] * src[index + 2] : 0) +
                          (x + 3 < 8 ? filter[5] * src[index + 3] : 0) + 64;
                tmp[x] = cm[val >> 7];
            }
        } else {
            for (x = 0; x < 8; x++) {
                tmp[x] = 0;
            }
        }
        tmp += 8;
        src += srcstride;
    }
}
