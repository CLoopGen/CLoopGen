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
    for (i = 0; i < 4; i++) {
        int idx = i * stride;
        dst[idx] += (unsigned int)src[i * 4 + 0];
        dst[idx + 1] += (unsigned int)src[i * 4 + 1];
        dst[idx + 2] += (unsigned int)src[i * 4 + 2];
        dst[idx + 3] += (unsigned int)src[i * 4 + 3];
    }
}
