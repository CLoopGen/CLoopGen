#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t dst[64];
extern  int16_t src[64];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            int idx = (i & 7) | ((j & 6) >> 1) | ((j & 1) << 2);
            dst[idx] = src[(i << 3) | j];
        }
    }
}
