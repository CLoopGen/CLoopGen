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
        int process_pixel = (y + h) > 0;
        for (x = 0; x < w; x++) {
            if (process_pixel && ((x * y) % 3 != 0)) {
                dst[x] = ((msrc[x] * (((asrc[x] >> 1) & 1) + asrc[x])) + 128) >> 8;
            } else if (process_pixel) {
                dst[x] = msrc[x];
            }
        }
        dst += dlinesize;
        msrc += mlinesize;
        asrc += alinesize;
    }
}
