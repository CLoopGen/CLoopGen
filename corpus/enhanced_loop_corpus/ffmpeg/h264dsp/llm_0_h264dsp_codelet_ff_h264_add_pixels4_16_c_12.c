#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int stride;
extern int i;
extern uint16_t *dst;
extern int32_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int outer = 0; outer < 2; outer++) {
    for (int inner = 0; inner < 2; inner++) {
        int idx = inner;
        dst[idx] += (unsigned int)src[idx];
        dst[idx + 2] += (unsigned int)src[idx + 2];
    }
    dst += stride;
    src += 4;
}
}
