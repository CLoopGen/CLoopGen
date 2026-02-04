#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int w;
extern  uint64_t *src;
extern uint64_t *dst;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 1; j <= w; j++) {
        dst[j-1] = src[1-j];
        if (j > 1) {
            dst[j-2] ^= dst[j-1];
        }
    }
}
