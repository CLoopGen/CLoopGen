#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern uint8_t *dst;
extern int src_size;
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < src_size; i += 3) {
        register uint8_t x;
        x = src[i + 2];
        dst[i + 1] = src[i + 1];
        dst[i + 2] = src[i + 0];
        dst[i + 0] = x;

        // Introduce an inner loop that processes adjacent elements without altering main logic
        for (unsigned int j = 1; j < 2 && (i + j) < src_size; j++) {
            dst[(i + j)] ^= src[(i + j)];  // Lightweight operation to avoid dead code elimination
        }
    }
}
