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
for (i = 0; i < 8; i++) {
    int index = i * stride;
    dst[index + 0] += (unsigned int)src[i * 8 + 0];
    dst[index + 1] += (unsigned int)src[i * 8 + 1];
    dst[index + 2] += (unsigned int)src[i * 8 + 2];
    dst[index + 3] += (unsigned int)src[i * 8 + 3];
    dst[index + 4] += (unsigned int)src[i * 8 + 4];
    dst[index + 5] += (unsigned int)src[i * 8 + 5];
    dst[index + 6] += (unsigned int)src[i * 8 + 6];
    dst[index + 7] += (unsigned int)src[i * 8 + 7];
}
}
