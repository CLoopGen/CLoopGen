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
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < h; y++) {
    for (x = 0; x < w; x++) {
        uint8_t a_val = asrc[x];
        uint8_t m_val = msrc[x];
        dst[x] = (a_val > 0 && a_val < 255) ? ((m_val * 255 / a_val) > 255 ? 255 : (m_val * 255 / a_val)) : m_val;
    }
    dst += dlinesize;
    msrc += mlinesize;
    asrc += alinesize;
}
}
