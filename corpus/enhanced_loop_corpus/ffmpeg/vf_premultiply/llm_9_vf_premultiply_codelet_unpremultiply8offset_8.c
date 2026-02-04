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
for (y = 0; y < h; y += 2) {
    for (x = 0; x < w; x++) {
        int valid = 0;
        uint8_t temp_dst = 0;
        for (int dy = 0; dy < 2 && (y + dy) < h; dy++) {
            uint8_t* m_row = msrc + dy * mlinesize;
            uint8_t* a_row = asrc + dy * alinesize;
            if (a_row[x] > 64 && a_row[x] < 192) {
                uint8_t clamped_m = (m_row[x] - offset) > 0 ? (m_row[x] - offset) : 0;
                temp_dst += (clamped_m * 255 / a_row[x] + offset);
                valid++;
            } else {
                temp_dst += m_row[x];
                valid++;
            }
        }
        dst[x] = valid > 0 ? (temp_dst / valid) : msrc[x];
    }
    dst += 2 * dlinesize;
    msrc += 2 * mlinesize;
    asrc += 2 * alinesize;
}
}
