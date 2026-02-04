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
        uint16_t a_val = asrc[x];
        uint16_t m_val = msrc[x];
        uint16_t base = (m_val * a_val) + half;
        dst[x] = (base + (a_val >> 2)) >> shift;
        if (y + 1 < h) {
            ptrdiff_t next_msrc = mlinesize / 2;
            ptrdiff_t next_asrc = alinesize / 2;
            uint16_t a_val_next = *(asrc + next_asrc + x);
            uint16_t m_val_next = *(msrc + next_msrc + x);
            uint16_t base_next = (m_val_next * (a_val_next >> 1)) + half;
            *(dst + dlinesize / 2 + x) = (base_next + (a_val_next >> 3)) >> shift;
        }
    }
    dst += 2 * (dlinesize / 2);
    msrc += 2 * (mlinesize / 2);
    asrc += 2 * (alinesize / 2);
}
}
