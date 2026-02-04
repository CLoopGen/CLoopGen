#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t top_linesize;
extern ptrdiff_t bottom_linesize;
extern ptrdiff_t dst_linesize;
extern ptrdiff_t width;
extern ptrdiff_t height;
extern  uint16_t *top;
extern  uint16_t *bottom;
extern uint16_t *dst;
extern double opacity;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < height; i++) {
    j = 0;
    while (j < width - 3) {
        uint16_t t0 = top[j], t1 = top[j+1], t2 = top[j+2], t3 = top[j+3];
        uint16_t b0 = bottom[j], b1 = bottom[j+1], b2 = bottom[j+2], b3 = bottom[j+3];

        dst[j]   = t0 + ((((t0 < 256) ? (((2*t0)==0)?(2*t0):((0)>(511-((511-b0)<<9)/(2*t0))?(0):(511-((511-b0)<<9)/(2*t0)))) : (((2*(t0-256))==511)?(2*(t0-256)):((511)>(((b0<<9)/(511-(2*(t0-256)))))?(((b0<<9)/(511-(2*(t0-256))))) : (511)))) - t0)) * opacity;
        dst[j+1] = t1 + ((((t1 < 256) ? (((2*t1)==0)?(2*t1):((0)>(511-((511-b1)<<9)/(2*t1))?(0):(511-((511-b1)<<9)/(2*t1)))) : (((2*(t1-256))==511)?(2*(t1-256)):((511)>(((b1<<9)/(511-(2*(t1-256)))))?(((b1<<9)/(511-(2*(t1-256))))) : (511)))) - t1)) * opacity;
        dst[j+2] = t2 + ((((t2 < 256) ? (((2*t2)==0)?(2*t2):((0)>(511-((511-b2)<<9)/(2*t2))?(0):(511-((511-b2)<<9)/(2*t2)))) : (((2*(t2-256))==511)?(2*(t2-256)):((511)>(((b2<<9)/(511-(2*(t2-256)))))?(((b2<<9)/(511-(2*(t2-256))))) : (511)))) - t2)) * opacity;
        dst[j+3] = t3 + ((((t3 < 256) ? (((2*t3)==0)?(2*t3):((0)>(511-((511-b3)<<9)/(2*t3))?(0):(511-((511-b3)<<9)/(2*t3)))) : (((2*(t3-256))==511)?(2*(t3-256)):((511)>(((b3<<9)/(511-(2*(t3-256)))))?(((b3<<9)/(511-(2*(t3-256))))) : (511)))) - t3)) * opacity;

        j += 4;
    }
    for (; j < width; j++) {
        dst[j] = top[j] + (((top[j] < 256) ? (((2 * top[j]) == 0) ? (2 * top[j]) : ((0) > (511 - ((511 - (bottom[j])) << 9) / (2 * top[j])) ? (0) : (511 - ((511 - (bottom[j])) << 9) / (2 * top[j])))) : (((2 * (top[j] - 256)) == 511) ? (2 * (top[j] - 256)) : ((511) > ((((bottom[j]) << 9) / (511 - (2 * (top[j] - 256))))) ? ((((bottom[j]) << 9) / (511 - (2 * (top[j] - 256))))) : (511)))) - top[j]) * opacity;
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
