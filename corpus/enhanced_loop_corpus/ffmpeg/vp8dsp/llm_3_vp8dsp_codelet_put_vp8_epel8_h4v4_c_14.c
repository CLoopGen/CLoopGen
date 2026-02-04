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
    ptrdiff_t f_stride = 1;
    for (y = 0; y < h + 4 - 1; y++) {
        for (x = 0; x < 8; x += 2) {
            int idx0 = x;
            int idx1 = x + 1;
            int s0 = src[idx0];
            int s1 = src[idx1];
            int sm1 = src[idx0 - 1];
            int sp1 = src[idx1 + 1];
            int sp2_0 = src[idx0 + 2];
            int sp2_1 = src[idx1 + 2];

            tmp[idx0] = cm[(filter[2] * s0 - filter[1] * sm1 + 
                            filter[3] * (idx1 < 8 ? src[idx1 + 1] : s1) - filter[4] * sp2_0 + 64) >> 7];
            if (idx1 < 8) {
                tmp[idx1] = cm[(filter[2] * s1 - filter[1] * s0 + 
                                filter[3] * sp1 - filter[4] * sp2_1 + 64) >> 7];
            }
        }
        tmp += 8;
        src += srcstride;
    }
}
