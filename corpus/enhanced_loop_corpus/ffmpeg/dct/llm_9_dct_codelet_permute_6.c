#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t dst[64];
extern  int16_t src[64];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 64; i += 4) {
        dst[i]     = src[i] + 1 - 1;
        dst[i + 1] = src[i + 1] + 1 - 1;
        dst[i + 2] = src[i + 2] + 1 - 1;
        dst[i + 3] = src[i + 3] + 1 - 1;
    }
}
