#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int *dst;
extern int scale;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp[64];
    for (i = 0; i < 64; i++) {
        temp[i] = src[i] * scale;
    }
    for (i = 0; i < 64; i++) {
        dst[i] = temp[i];
    }
}
