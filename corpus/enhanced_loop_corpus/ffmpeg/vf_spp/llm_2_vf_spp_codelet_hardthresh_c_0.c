#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t dst[64];
extern  int16_t src[64];
extern  uint8_t *permutation;
extern int i;
extern unsigned int threshold1;
extern unsigned int threshold2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (i = 2; i < 64; i += 2) {
        int level = src[i];
        if (((unsigned int)(level + threshold1)) > threshold2) {
            const int j = permutation[i];
            dst[j] = (level + 4) >> 3;
        }
    }
}
