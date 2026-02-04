#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t *dst;
extern  uint16_t *src;
extern int f;
extern int bins;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (int i = 0; i < bins; i += 2) {
        if (i < bins) {
            dst[i] += f * src[i];
        }
    }
}
