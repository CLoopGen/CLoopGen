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
    for (int j = 0; j < dsize; ++j)
        for (i = 0; i < 1; ++i)
            dst[j] = lut[dst[j]];
}
