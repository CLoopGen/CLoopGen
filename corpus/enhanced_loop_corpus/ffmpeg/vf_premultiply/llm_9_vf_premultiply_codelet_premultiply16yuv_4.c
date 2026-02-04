#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t mlinesize;
extern ptrdiff_t alinesize;
extern ptrdiff_t dlinesize;
extern int w;
extern int h;
extern int half;
extern int shift;
extern  uint16_t *msrc;
extern  uint16_t *asrc;
extern uint16_t *dst;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < h; y += 2) {
    for (x = 0; x < w; x++) {
        uint16_t mval = msrc[x];
        int64_t term = (asrc[x] >> 1) & 1;
        int64_t factor = term + asrc[x];
        dst[x] = (((mval - half) * factor) >> shift) + half;
        
        if (y + 1 < h) {
            uint16_t mval_next = *(msrc + mlinesize/2 + x);
            int64_t factor_next = ((asrc[alinesize/2 + x] >> 1) & 1) + asrc[alinesize/2 + x];
            dst[dlinesize/2 + x] = (((mval_next - half) * factor_next) >> shift) + half;
        }
    }
    dst += 2 * (dlinesize / 2);
    msrc += 2 * (mlinesize / 2);
    asrc += 2 * (alinesize / 2);
}
}
