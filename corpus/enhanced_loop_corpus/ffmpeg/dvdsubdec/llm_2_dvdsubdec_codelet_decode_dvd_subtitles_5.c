#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern int pos;
extern uint8_t *alpha;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 2, unrolled to handle even indices
    for (i = 0; i < 256; i += 2) {
        alpha[i] = 255 - buf[pos + i];
        if (i + 1 < 256) {
            alpha[i + 1] = 255 - buf[pos + i + 1];
        }
    }
}
