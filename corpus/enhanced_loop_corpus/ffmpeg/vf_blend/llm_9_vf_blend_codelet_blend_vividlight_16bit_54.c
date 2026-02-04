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
        dst[j]   = t0 + (((t0 < 32768) ? 
                         ((2*t0 == 0) ? 0 : (0 > (65535 - ((65535 - b0) << 16)/(2*t0 + 1)) ? 0 : (65535 - ((65535 - b0) << 16)/(2*t0 + 1)))) :
                         ((2*(t0-32768) == 65535) ? 65535 : (65535 > ((b0 << 16)/(65535 - 2*(t0-32768) + 1)) ? ((b0 << 16)/(65535 - 2*(t0-32768) + 1)) : 65535))) - t0) * opacity;
        dst[j+1] = t1 + (((t1 < 32768) ? 
                         ((2*t1 == 0) ? 0 : (0 > (65535 - ((65535 - b1) << 16)/(2*t1 + 1)) ? 0 : (65535 - ((65535 - b1) << 16)/(2*t1 + 1)))) :
                         ((2*(t1-32768) == 65535) ? 65535 : (65535 > ((b1 << 16)/(65535 - 2*(t1-32768) + 1)) ? ((b1 << 16)/(65535 - 2*(t1-32768) + 1)) : 65535))) - t1) * opacity;
        dst[j+2] = t2 + (((t2 < 32768) ? 
                         ((2*t2 == 0) ? 0 : (0 > (65535 - ((65535 - b2) << 16)/(2*t2 + 1)) ? 0 : (65535 - ((65535 - b2) << 16)/(2*t2 + 1)))) :
                         ((2*(t2-32768) == 65535) ? 65535 : (65535 > ((b2 << 16)/(65535 - 2*(t2-32768) + 1)) ? ((b2 << 16)/(65535 - 2*(t2-32768) + 1)) : 65535))) - t2) * opacity;
        dst[j+3] = t3 + (((t3 < 32768) ? 
                         ((2*t3 == 0) ? 0 : (0 > (65535 - ((65535 - b3) << 16)/(2*t3 + 1)) ? 0 : (65535 - ((65535 - b3) << 16)/(2*t3 + 1)))) :
                         ((2*(t3-32768) == 65535) ? 65535 : (65535 > ((b3 << 16)/(65535 - 2*(t3-32768) + 1)) ? ((b3 << 16)/(65535 - 2*(t3-32768) + 1)) : 65535))) - t3) * opacity;
        j += 4;
    }
    for (; j < width; j++) {
        dst[j] = top[j] + (((top[j] < 32768) ? (((2 * top[j]) == 0) ? (2 * top[j]) : ((0) > (65535 - ((65535 - (bottom[j])) << 16) / (2 * top[j])) ? (0) : (65535 - ((65535 - (bottom[j])) << 16) / (2 * top[j])))) : (((2 * (top[j] - 32768)) == 65535) ? (2 * (top[j] - 32768)) : ((65535) > ((((bottom[j]) << 16) / (65535 - (2 * (top[j] - 32768))))) ? ((((bottom[j]) << 16) / (65535 - (2 * (top[j] - 32768))))) : (65535)))) - top[j]) * opacity;
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
