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
    // Variant 1: Consecutive memory access with pointer arithmetic unrolled by 2
    // This variant assumes w is even and processes two elements per iteration to promote consecutive, sequential access
    for (y = 0; y < h; y++) {
        uint16_t *mdst = dst;
        uint16_t *mmsrc = msrc;
        uint16_t *masrc = asrc;
        for (x = 0; x < w; x += 2) {
            mdst[0] = ((mmsrc[0] * (((masrc[0] >> 1) & 1) + masrc[0])) + half) >> shift;
            mdst[1] = ((mmsrc[1] * (((masrc[1] >> 1) & 1) + masrc[1])) + half) >> shift;
            mdst += 2;
            mmsrc += 2;
            masrc += 2;
        }
        dst += dlinesize / 2;
        msrc += mlinesize / 2;
        asrc += alinesize / 2;
    }
}
