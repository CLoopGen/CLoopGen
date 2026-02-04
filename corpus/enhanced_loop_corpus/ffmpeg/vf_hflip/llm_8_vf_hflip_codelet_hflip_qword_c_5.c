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
    for (j = 0; j < w; j += 2) {
        if (j + 1 < w) {
            dst[j]     = src[-j];
            dst[j + 1] = src[-(j + 1)];
        } else {
            dst[j] = src[-j];
        }
    }
}
