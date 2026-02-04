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
    for (i = 0; i < 64; i += 4) {
        dst[i]     = src[i]     * scale;
        dst[i + 1] = src[i + 1] * scale;
        dst[i + 2] = src[i + 2] * scale;
        dst[i + 3] = src[i + 3] * scale;
    }
}
