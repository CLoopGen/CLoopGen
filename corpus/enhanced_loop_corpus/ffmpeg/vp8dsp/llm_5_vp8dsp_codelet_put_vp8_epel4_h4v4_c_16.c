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
        for (x = 0; x < 4; x++) {
            int index = x;
            int offset = 0;
            if (y >= 2) {
                offset = srcstride;
            }
            int val = filter[2] * src[index + 0] - filter[1] * src[index - 1] +
                      filter[3] * src[index + 1] - filter[4] * src[index + 2] + 64;
            tmp[index] = cm[val >> 7];
        }
        tmp += 4;
        src += srcstride;
    }
}
