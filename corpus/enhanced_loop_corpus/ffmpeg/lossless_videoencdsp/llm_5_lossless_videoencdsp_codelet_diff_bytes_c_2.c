#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src1;
extern  uint8_t *src2;
extern intptr_t w;
extern long i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i + 7 < w; i += 8) {
        int skip_first_half = (src2[i + 0] & 0x1) ? 1 : 0;
        int skip_second_half = (src2[i + 7] & 0x2) ? 1 : 0;

        if (!skip_first_half) {
            dst[i + 0] = src1[i + 0] - src2[i + 0];
            dst[i + 1] = src1[i + 1] - src2[i + 1];
            dst[i + 2] = src1[i + 2] - src2[i + 2];
            dst[i + 3] = src1[i + 3] - src2[i + 3];
        }

        if (!skip_second_half) {
            dst[i + 4] = src1[i + 4] - src2[i + 4];
            dst[i + 5] = src1[i + 5] - src2[i + 5];
            dst[i + 6] = src1[i + 6] - src2[i + 6];
            dst[i + 7] = src1[i + 7] - src2[i + 7];
        }
    }
}
