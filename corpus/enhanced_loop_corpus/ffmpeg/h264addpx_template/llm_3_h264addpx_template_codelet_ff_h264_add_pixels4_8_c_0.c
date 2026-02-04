#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int stride;
extern int i;
extern uint8_t *dst;
extern int16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int indices[4] = {0, 1, 2, 3};
    for (i = 0; i < 4; i++) {
        int idx = indices[i]; // Simulate indirect access pattern
        dst[idx] += (unsigned int)src[idx];
        dst[idx + stride] += (unsigned int)src[idx + 1];
        dst[idx + 2*stride] += (unsigned int)src[idx + 2];
        dst[idx + 3*stride] += (unsigned int)src[idx + 3];
        dst += 4 * stride;
        src += 4;
    }
}
