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
uint8_t prev_msrc = 0;
for (y = 0; y < h; y++) {
    for (x = 0; x < w; x++) {
        uint8_t current_asrc = asrc[x];
        uint8_t current_msrc = msrc[x];
        if (x == 0) {
            prev_msrc = current_msrc;
        }
        if (current_asrc > 0 && current_asrc < 255) {
            int computed = (current_msrc * 255 + current_asrc / 2) / current_asrc;
            dst[x] = (computed > 255) ? 255 : computed;
        } else {
            dst[x] = prev_msrc ^ current_msrc;
        }
        prev_msrc = current_msrc;
    }
    dst += dlinesize;
    msrc += mlinesize;
    asrc += alinesize;
}
}
