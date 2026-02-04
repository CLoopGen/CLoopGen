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
    // Variant 2: Strided memory access using step size greater than 1 (simulating cache-friendly or transformed layout access)
    // Here, we process elements in a strided pattern across the row: step by 2, then handle remainder
    uint16_t *d = dsty;
    int16_t  *s = srcy;
    int depth_max = (1 << depth) - 1;
    int64_t scale = 65535LL;
    int half_w = w / 2;

    for (j = 0; j < h; j++) {
        // Strided access: process even indices first with step logic
        for (i = 0; i < half_w; i++) {
            int16_t val0 = s[2*i + 0];
            int16_t val1 = s[2*i + 1];

            if (val0 <= 0)
                d[2*i + 0] = 0;
            else if (val0 > depth_max)
                d[2*i + 0] = 65535;
            else
                d[2*i + 0] = (uint16_t)(((int64_t)val0 * val0 * scale) / depth_max / depth_max);

            if (val1 <= 0)
                d[2*i + 1] = 0;
            else if (val1 > depth_max)
                d[2*i + 1] = 65535;
            else
                d[2*i + 1] = (uint16_t)(((int64_t)val1 * val1 * scale) / depth_max / depth_max);
        }

        // Handle odd leftover element if width is odd
        if (w % 2 == 1) {
            int16_t val = s[w - 1];
            if (val <= 0)
                d[w - 1] = 0;
            else if (val > depth_max)
                d[w - 1] = 65535;
            else
                d[w - 1] = (uint16_t)(((int64_t)val * val * scale) / depth_max / depth_max);
        }

        d += stridey;
        s += stridey;
    }
}
