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
extern int offset;
extern  uint16_t *msrc;
extern  uint16_t *asrc;
extern uint16_t *dst;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < h; y++) {
    for (x = 0; x < w; x += 2) {
        int64_t a_val1 = asrc[x] >> 1;
        int64_t a_val2 = asrc[x + 1] >> 1;
        int64_t m_val1 = msrc[x];
        int64_t m_val2 = msrc[x + 1];
        dst[x]     = ((((m_val1 - offset) * ((a_val1 & 1) + a_val1)) + half) >> shift) + offset;
        dst[x + 1] = ((((m_val2 - offset) * ((a_val2 & 1) + a_val2)) + half) >> shift) + offset;
    }
    dst += dlinesize / 2;
    msrc += mlinesize / 2;
    asrc += alinesize / 2;
}
}
