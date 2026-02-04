#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t mlinesize;
extern ptrdiff_t alinesize;
extern ptrdiff_t dlinesize;
extern int w;
extern int h;
extern int max;
extern int offset;
extern  uint16_t *msrc;
extern  uint16_t *asrc;
extern uint16_t *dst;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < h; y++) {
    ptrdiff_t m_offset = 0, a_offset = 0, d_offset = 0;
    for (x = 0; x < w; x++) {
        int idx = x;
        if (asrc[a_offset + idx] > 0 && asrc[a_offset + idx] < max)
            dst[d_offset + idx] = ((((((msrc[m_offset + idx] - offset) > (0) ? (msrc[m_offset + idx] - offset) : (0)) * (unsigned int)max / asrc[a_offset + idx] + offset) > (max) ? (max) : (((msrc[m_offset + idx] - offset) > (0) ? (msrc[m_offset + idx] - offset) : (0)) * (unsigned int)max / asrc[a_offset + idx] + offset))) > (0) ? (((((msrc[m_offset + idx] - offset) > (0) ? (msrc[m_offset + idx] - offset) : (0)) * (unsigned int)max / asrc[a_offset + idx] + offset) > (max) ? (max) : (((msrc[m_offset + idx] - offset) > (0) ? (msrc[m_offset + idx] - offset) : (0)) * (unsigned int)max / asrc[a_offset + idx] + offset))) : (0));
        else
            dst[d_offset + idx] = msrc[m_offset + idx];
    }
    dst += dlinesize / 2;
    msrc += mlinesize / 2;
    asrc += alinesize / 2;
}
}
