#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *msrc;
extern  uint8_t *asrc;
extern uint8_t *dst;
extern ptrdiff_t mlinesize;
extern ptrdiff_t alinesize;
extern ptrdiff_t dlinesize;
extern int w;
extern int h;
extern int offset;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < h; y++) {
    for (x = 0; x < w; x += 4) { // Strided access with step 4 (SIMD-like pattern)
        int x1 = x + 1;
        int x2 = x + 2;
        int x3 = x + 3;

        // Process 4 elements per iteration (unrolled with strided memory access)
        if (x < w && asrc[x] > 0 && asrc[x] < 255) {
            dst[x] = ((((msrc[x] - offset) > (0) ? (msrc[x] - offset) : (0)) * 255 / asrc[x] + offset) > 255 ? 255 : (((msrc[x] - offset) > (0) ? (msrc[x] - offset) : (0)) * 255 / asrc[x] + offset));
        } else if (x < w) {
            dst[x] = msrc[x];
        }

        if (x1 < w && asrc[x1] > 0 && asrc[x1] < 255) {
            dst[x1] = ((((msrc[x1] - offset) > (0) ? (msrc[x1] - offset) : (0)) * 255 / asrc[x1] + offset) > 255 ? 255 : (((msrc[x1] - offset) > (0) ? (msrc[x1] - offset) : (0)) * 255 / asrc[x1] + offset));
        } else if (x1 < w) {
            dst[x1] = msrc[x1];
        }

        if (x2 < w && asrc[x2] > 0 && asrc[x2] < 255) {
            dst[x2] = ((((msrc[x2] - offset) > (0) ? (msrc[x2] - offset) : (0)) * 255 / asrc[x2] + offset) > 255 ? 255 : (((msrc[x2] - offset) > (0) ? (msrc[x2] - offset) : (0)) * 255 / asrc[x2] + offset));
        } else if (x2 < w) {
            dst[x2] = msrc[x2];
        }

        if (x3 < w && asrc[x3] > 0 && asrc[x3] < 255) {
            dst[x3] = ((((msrc[x3] - offset) > (0) ? (msrc[x3] - offset) : (0)) * 255 / asrc[x3] + offset) > 255 ? 255 : (((msrc[x3] - offset) > (0) ? (msrc[x3] - offset) : (0)) * 255 / asrc[x3] + offset));
        } else if (x3 < w) {
            dst[x3] = msrc[x3];
        }
    }
    dst += dlinesize;
    msrc += mlinesize;
    asrc += alinesize;
}
}
