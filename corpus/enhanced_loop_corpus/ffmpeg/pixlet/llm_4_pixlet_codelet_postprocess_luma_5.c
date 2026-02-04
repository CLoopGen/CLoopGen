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
        if (val <= 0) {
            dsty[i] = 0;
            continue;
        }
        int threshold = (1 << depth) - 1;
        if (val >= threshold) {
            dsty[i] = 65535;
        } else {
            dsty[i] = ((int64_t)val * val * 65535) / ((int64_t)threshold * threshold);
        }
    }
    dsty += stridey;
    srcy += stridey;
}
}
