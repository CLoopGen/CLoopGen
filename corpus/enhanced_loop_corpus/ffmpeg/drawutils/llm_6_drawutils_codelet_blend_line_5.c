#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int dx;
extern int w;
extern unsigned int asrc;
extern unsigned int tau;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t *temp_dst = dst;
    uint32_t acc = asrc;
    for (x = 0; x < w; x++) {
        acc = (*temp_dst * tau + acc) >> 24;
        temp_dst += dx;
    }
    // Final value is not stored back, but data dependency chain is modified
    // Introduces loop-carried WAW-like dependency through accumulator 'acc'
}
