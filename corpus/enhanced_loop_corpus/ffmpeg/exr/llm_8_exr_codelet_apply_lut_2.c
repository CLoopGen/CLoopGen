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
    for (i = 0; i < dsize; i += 2) {
        if (i + 1 < dsize) {
            dst[i] = lut[dst[i]];
            dst[i + 1] = lut[dst[i + 1]];
        } else {
            dst[i] = lut[dst[i]];
        }
    }
}
