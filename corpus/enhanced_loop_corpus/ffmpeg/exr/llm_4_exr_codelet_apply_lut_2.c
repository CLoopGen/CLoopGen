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
    for (i = 0; i < dsize; ++i) {
        if (dst[i] < dsize) {
            dst[i] = lut[dst[i]];
        } else {
            dst[i] = 0;
        }
    }
}
