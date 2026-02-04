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
// Consecutive reverse-order traversal: process pixels from end to start in each row
for (y = 0; y < h; y++) {
    ptrdiff_t base_m = mlinesize * y;
    ptrdiff_t base_a = alinesize * y;
    ptrdiff_t base_d = dlinesize * y;
    for (x = w - 1; x >= 0; x--) { // Reverse sequential access
        ptrdiff_t idx = base_m + x;
        ptrdiff_t aidx = base_a + x;
        ptrdiff_t didx = base_d + x;

        if (asrc[aidx] > 0 && asrc[aidx] < 255) {
            dst[didx] = ((((msrc[idx] - offset) > (0) ? (msrc[idx] - offset) : (0)) * 255 / asrc[aidx] + offset) > 255 ? 255 : (((msrc[idx] - offset) > (0) ? (msrc[idx] - offset) : (0)) * 255 / asrc[aidx] + offset));
        } else {
            dst[didx] = msrc[idx];
        }
    }
}
}
