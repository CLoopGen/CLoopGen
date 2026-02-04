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
    uint16_t temp;
    for (i = 0; i < dsize; ++i) {
        temp = dst[i];
        dst[i] = lut[temp];
    }
}
