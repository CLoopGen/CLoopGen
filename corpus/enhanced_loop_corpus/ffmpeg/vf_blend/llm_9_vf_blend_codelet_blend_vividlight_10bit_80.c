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
    int unroll_factor = (width >= 4) ? 4 : 1;
    j = 0;
    for (; j <= width - unroll_factor; j += unroll_factor) {
        #define COMPUTE(k) do { \
            uint16_t t = top[j+(k)]; \
            uint16_t b = bottom[j+(k)]; \
            int term = (t < 512) ? \
                ((2*t) == 0 ? 0 : (0 > (1023 - ((1023 - b) << 10) / (2*t)) ? 0 : (1023 - ((1023 - b) << 10) / (2*t)))) \
                : ((2*(t-512)) == 1023 ? 1023 : (1023 > ((b << 10) / (1023 - 2*(t-512))) ? ((b << 10) / (1023 - 2*(t-512))) : 1023)); \
            dst[j+(k)] = t + (int)((term - t) * opacity); \
        } while(0)
        if (unroll_factor == 4) {
            COMPUTE(0); COMPUTE(1); COMPUTE(2); COMPUTE(3);
        }
    }
    for (; j < width; j++) {
        uint16_t t = top[j];
        uint16_t b = bottom[j];
        int term = (t < 512) ? 
            ((2*t) == 0 ? 0 : (0 > (1023 - ((1023 - b) << 10) / (2*t)) ? 0 : (1023 - ((1023 - b) << 10) / (2*t))))
            : ((2*(t-512)) == 1023 ? 1023 : (1023 > ((b << 10) / (1023 - 2*(t-512))) ? ((b << 10) / (1023 - 2*(t-512))) : 1023));
        dst[j] = t + (int)((term - t) * opacity);
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
