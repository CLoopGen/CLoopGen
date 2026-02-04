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
        uint16_t index = dst[i];
        if (index % 2 == 0) {
            dst[i] = lut[index];
        }
    }
}
