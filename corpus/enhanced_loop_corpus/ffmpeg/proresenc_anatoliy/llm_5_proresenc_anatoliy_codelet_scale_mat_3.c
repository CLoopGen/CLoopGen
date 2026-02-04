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
    for (i = 0; i < 64; i++) {
        if (i % 2 == 0) {
            dst[i] = src[i] * scale;
        } else {
            dst[i] = src[i] * scale * 2;
        }
    }
}
