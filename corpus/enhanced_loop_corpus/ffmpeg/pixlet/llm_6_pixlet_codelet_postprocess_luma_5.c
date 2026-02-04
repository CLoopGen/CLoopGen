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
    int64_t max_val = (1LL << depth) - 1;
    int64_t scale = 65535;
    for (j = 0; j < h; j++) {
        for (i = 0; i < w; i++) {
            int16_t val = srcy[i];
            uint16_t result = 0;
            if (val > 0) {
                if (val > max_val)
                    result = 65535;
                else
                    result = (uint16_t)((val * val * scale) / (max_val * max_val));
            }
            dsty[i] = result;
        }
        dsty += stridey;
        srcy += stridey;
    }
}
