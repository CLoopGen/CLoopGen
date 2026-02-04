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
    // Variant 2: Strided memory access with stride of 4
    // Processes every 4th element in each inner loop pass, then repeats for remaining offsets
    // This changes access pattern from sequential to strided, potentially improving cache behavior for certain data layouts
    for (y = 0; y < h; y++) {
        for (int offset = 0; offset < 4; offset++) {
            for (x = offset; x < w; x += 4) {
                dst[x] = ((msrc[x] * (((asrc[x] >> 1) & 1) + asrc[x])) + half) >> shift;
            }
        }
        dst += dlinesize / 2;
        msrc += mlinesize / 2;
        asrc += alinesize / 2;
    }
}
