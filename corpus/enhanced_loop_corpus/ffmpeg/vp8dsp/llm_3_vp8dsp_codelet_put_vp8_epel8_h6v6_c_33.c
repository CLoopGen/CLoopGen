#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dststride;
extern int h;
extern  uint8_t *filter;
extern  uint8_t *cm;
extern int x;
extern int y;
extern uint8_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = 0; y < h; y++) {
        for (x = 0; x < 8; x += 2) {
            int offset0 = x + 0 * 8;
            int offset1 = x - 1 * 8;
            int offset2 = x - 2 * 8;
            int offset3 = x + 1 * 8;
            int offset4 = x + 2 * 8;
            int offset5 = x + 3 * 8;

            int val0 = (filter[2] * tmp[offset0] - filter[1] * tmp[offset1] + filter[0] * tmp[offset2] +
                        filter[3] * tmp[offset3] - filter[4] * tmp[offset4] + filter[5] * tmp[offset5] + 64) >> 7;
            dst[x] = cm[val0];

            if (x + 1 < 8) {
                offset0++; offset1++; offset2++; offset3++; offset4++; offset5++;
                int val1 = (filter[2] * tmp[offset0] - filter[1] * tmp[offset1] + filter[0] * tmp[offset2] +
                            filter[3] * tmp[offset3] - filter[4] * tmp[offset4] + filter[5] * tmp[offset5] + 64) >> 7;
                dst[x + 1] = cm[val1];
            }
        }
        dst += dststride;
        tmp += 8;
    }
}
