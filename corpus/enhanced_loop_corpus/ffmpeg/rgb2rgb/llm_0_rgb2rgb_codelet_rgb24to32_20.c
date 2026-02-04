#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern uint8_t *dst;
extern int src_size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (j = 0; j < src_size; j += 3) {
    int i = j / 3;
    dst[4 * i + 0] = src[j + 2];
    dst[4 * i + 1] = src[j + 1];
    dst[4 * i + 2] = src[j + 0];
    dst[4 * i + 3] = 255;
}
}
