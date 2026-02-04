#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t *dst;
extern  uint16_t *src1;
extern  uint16_t *src2;
extern unsigned int mask;
extern int w;
extern long i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive write with reverse read order
    long idx = w - 1 - i;
    for (; i < w; i++, idx--)
        dst[i] = (src1[idx] - src2[idx]) & mask;
}
