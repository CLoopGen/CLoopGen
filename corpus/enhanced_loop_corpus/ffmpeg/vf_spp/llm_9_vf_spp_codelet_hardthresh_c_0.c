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
    for (i = 1; i < 63; i++) {
        int level1 = src[i];
        int level2 = src[i + 1];
        if (((unsigned int)(level1 + threshold1)) > threshold2) {
            const int j1 = permutation[i];
            dst[j1] = (level1 + 4) >> 3;
        }
        if (((unsigned int)(level2 + threshold1)) > threshold2) {
            const int j2 = permutation[i + 1];
            dst[j2] = (level2 + 4) >> 3;
        }
    }
}
