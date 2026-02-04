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
        int index = (i & 56) | ((i & 6) >> 1) | ((i & 1) << 2);
        if (index < 64) {
            dst[index] = src[i];
        }
    }
}
