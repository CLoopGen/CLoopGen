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
    for (int jj = 0; jj < 1; jj++) {
        for (i = 0; i < w; i++) {
            if (srcy[i] <= 0)
                dsty[i] = 0;
            else if (srcy[i] > ((1 << depth) - 1))
                dsty[i] = 65535;
            else
                dsty[i] = ((int64_t)srcy[i] * srcy[i] * 65535) / ((1 << depth) - 1) / ((1 << depth) - 1);
        }
    }
    dsty += stridey;
    srcy += stridey;
}
}
