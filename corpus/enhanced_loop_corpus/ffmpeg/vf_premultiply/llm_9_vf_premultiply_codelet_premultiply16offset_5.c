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
for (y = 0; y < h; y += 2) {
    for (x = 0; x < w; x++) {
        uint16_t m = msrc[x];
        int64_t a = asrc[x];
        int64_t temp = ((m - offset) * ((a + (a & 1))) + half) >> shift;
        dst[x] = temp + offset;
        
        if (y + 1 < h) {
            uint16_t m_next = ((uint16_t*)(((uint8_t*)msrc) + mlinesize))[x];
            int64_t a_next = ((uint16_t*)(((uint8_t*)asrc) + alinesize))[x];
            int64_t temp_next = (((m_next - offset) * ((a_next + (a_next & 1))) + half) >> shift);
            ((uint16_t*)(((uint8_t*)dst) + dlinesize))[x] = temp_next + offset;
        }
    }
    dst += 2 * (dlinesize / 2);
    msrc += 2 * (mlinesize / 2);
    asrc += 2 * (alinesize / 2);
}
}
