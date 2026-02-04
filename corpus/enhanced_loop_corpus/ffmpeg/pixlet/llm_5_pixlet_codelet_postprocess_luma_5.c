#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int w;
extern int h;
extern int depth;
extern uint16_t *dsty;
extern int16_t *srcy;
extern ptrdiff_t stridey;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < h; j++) {
    for (i = 0; i < w; i++) {
        int16_t val = srcy[i];
        int threshold = (1 << depth) - 1;
        uint16_t result = 0;

        if (val > 0) {
            if (val < threshold) {
                result = (uint16_t)(((int64_t)val * val * 65535) / ((int64_t)threshold * threshold));
            } else {
                result = 65535;
            }
        }
        dsty[i] = result;
    }
    dsty += stridey;
    srcy += stridey;
}
}
