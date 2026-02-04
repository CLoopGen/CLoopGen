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
            for (x = 0; x < 16; x++) {
                int index = (filter[2] * src[x + 0 * 1] - filter[1] * src[x - 1 * 1] +
                             filter[3] * src[x + 1 * 1] - filter[4] * src[x + 2 * 1] + 64) >> 7;
                tmp[x] = cm[index];
            }
        } else {
            for (x = 0; x < 8; x++) {
                int index1 = (filter[2] * src[x + 0] - filter[1] * src[x - 1] +
                              filter[3] * src[x + 1] - filter[4] * src[x + 2] + 64) >> 7;
                int index2 = (filter[2] * src[x + 8 + 0] - filter[1] * src[x + 8 - 1] +
                              filter[3] * src[x + 8 + 1] - filter[4] * src[x + 8 + 2] + 64) >> 7;
                tmp[x] = cm[index1];
                tmp[x + 8] = cm[index2];
            }
        }
        tmp += 16;
        src += srcstride;
    }
}
