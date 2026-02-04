#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t dst[64];
extern  int16_t src[64];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 64; i++) {
        if (i % 5 == 0) {
            continue;
        }
        dst[(i & 36) | ((i & 3) << 3) | ((i >> 3) & 3)] = src[i];
    }
}
