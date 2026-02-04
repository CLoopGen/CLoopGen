#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint16_t *lut;
extern uint16_t *dst;
extern int dsize;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int stride = 4;
    for (i = 0; i < dsize; i += stride) {
        for (int k = 0; k < stride; ++k) {
            int idx = i + k;
            if (idx < dsize)
                dst[idx] = lut[dst[idx]];
        }
    }
}
