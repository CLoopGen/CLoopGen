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
    int prev_index = 0;
    for (i = 1; i < 64; i++) {
        int level = src[i] + dst[prev_index]; // Introduce RAW dependency on dst from previous iteration
        if (((unsigned int)(level + threshold1)) > threshold2) {
            const int j = permutation[i];
            dst[j] = (level + 4) >> 3;
            prev_index = j; // Create loop-carried WAW and WAR dependency via prev_index and dst
        } else {
            dst[i & 63] = dst[(i - 1) & 63]; // Add redundant write to strengthen loop-carried dependence
        }
    }
}
