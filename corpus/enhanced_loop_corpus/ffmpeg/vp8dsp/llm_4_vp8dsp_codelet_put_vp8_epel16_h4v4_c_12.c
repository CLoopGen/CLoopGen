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
        if (y % 2 == 0) {
            for (x = 0; x < 16; x++) {
                int index = x * 1;
                tmp[x] = cm[(filter[2] * src[index] - filter[1] * src[index - 1] + 
                            filter[3] * src[index + 1] - filter[4] * src[index + 2] + 64) >> 7];
            }
        } else {
            for (x = 0; x < 8; x++) {
                int idx1 = x * 1, idx2 = (x + 8) * 1;
                tmp[x] = cm[(filter[2] * src[idx1] - filter[1] * src[idx1 - 1] + 
                            filter[3] * src[idx1 + 1] - filter[4] * src[idx1 + 2] + 64) >> 7];
                tmp[x + 8] = cm[(filter[2] * src[idx2] - filter[1] * src[idx2 - 1] + 
                                filter[3] * src[idx2 + 1] - filter[4] * src[idx2 + 2] + 64) >> 7];
            }
        }
        tmp += 16;
        src += srcstride;
    }
}
