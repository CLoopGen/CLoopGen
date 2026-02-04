#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t dst[64];
extern  int16_t src[64];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < 8; j++) {
        for (int k = 0; k < 8; k++) {
            int i = (j << 3) | k;
            if (i < 64) {
                dst[(i & 36) | ((i & 3) << 3) | ((i >> 3) & 3)] = src[i];
            }
        }
    }
}
