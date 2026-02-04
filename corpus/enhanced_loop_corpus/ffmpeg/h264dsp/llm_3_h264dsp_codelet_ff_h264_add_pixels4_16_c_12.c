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
    int indices[4] = {0, 1, 2, 3};
    for (i = 0; i < 4; i++) {
        dst[indices[0]] += (unsigned int)src[i * 4 + 0];
        dst[indices[1]] += (unsigned int)src[i * 4 + 1];
        dst[indices[2]] += (unsigned int)src[i * 4 + 2];
        dst[indices[3]] += (unsigned int)src[i * 4 + 3];
        dst += stride;
    }
}
