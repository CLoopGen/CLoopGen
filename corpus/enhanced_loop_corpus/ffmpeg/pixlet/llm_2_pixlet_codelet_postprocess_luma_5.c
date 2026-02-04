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
    // Variant 1: Consecutive memory access with pointer arithmetic
    uint16_t *d = dsty;
    int16_t  *s = srcy;
    int depth_max = (1 << depth) - 1;
    int64_t scale = 65535LL;

    for (j = 0; j < h; j++) {
        for (i = 0; i < w; i++) {
            int16_t val = s[i];
            if (val <= 0)
                d[i] = 0;
            else if (val > depth_max)
                d[i] = 65535;
            else
                d[i] = (uint16_t)(((int64_t)val * val * scale) / depth_max / depth_max);
        }
        d += stridey;
        s += stridey;
    }
}
