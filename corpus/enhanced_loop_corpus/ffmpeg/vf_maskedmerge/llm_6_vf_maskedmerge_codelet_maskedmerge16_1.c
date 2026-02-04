#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t blinesize;
extern ptrdiff_t olinesize;
extern ptrdiff_t mlinesize;
extern ptrdiff_t dlinesize;
extern int w;
extern int h;
extern int half;
extern int shift;
extern  uint16_t *bsrc;
extern  uint16_t *osrc;
extern  uint16_t *msrc;
extern uint16_t *dst;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ptrdiff_t b_offset = 0;
    ptrdiff_t o_offset = 0;
    ptrdiff_t m_offset = 0;
    ptrdiff_t d_offset = 0;
    for (y = 0; y < h; y++) {
        for (x = 0; x < w; x++) {
            uint16_t b_val = bsrc[b_offset + x];
            uint16_t o_val = osrc[o_offset + x];
            uint16_t m_val = msrc[m_offset + x];
            dst[d_offset + x] = b_val + ((m_val * (o_val - b_val) + half) >> shift);
        }
        b_offset += blinesize / 2;
        o_offset += olinesize / 2;
        m_offset += mlinesize / 2;
        d_offset += dlinesize / 2;
    }
}
