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
    ptrdiff_t offset = i * 4;
    for (j = 0; j < width - 3; j += 4) {
        #define PROCESS_PIXEL(idx) \
            do { \
                uint16_t t = top[j + idx]; \
                uint16_t b = bottom[j + idx]; \
                uint16_t comp = (b == 65535) ? 65535 : ((t * t / (65535 - b)) > 65535 ? 65535 : (t * t / (65535 - b))); \
                dst[j + idx] = t + (comp - t) * opacity; \
            } while(0)
        PROCESS_PIXEL(0);
        PROCESS_PIXEL(1);
        PROCESS_PIXEL(2);
        PROCESS_PIXEL(3);
    }
    for (; j < width; j++) {
        dst[j] = top[j] + (((bottom[j] == 65535) ? bottom[j] : ((65535) > ((top[j] * top[j] / (65535 - bottom[j]))) ? ((top[j] * top[j] / (65535 - bottom[j]))) : (65535))) - top[j]) * opacity;
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
