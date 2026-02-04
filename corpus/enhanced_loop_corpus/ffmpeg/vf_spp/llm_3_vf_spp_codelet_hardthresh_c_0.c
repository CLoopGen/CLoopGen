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
    // Variant 2: Consecutive forward write pattern using direct indexing with temporary accumulation
    int temp_dst[64] = {0};
    int write_idx = 0;
    for (i = 1; i < 64; i++) {
        int level = src[i];
        if (((unsigned int)(level + threshold1)) > threshold2) {
            temp_dst[write_idx++] = (level + 4) >> 3;
        }
    }
    // Flush accumulated results consecutively into dst array
    for (i = 0; i < write_idx && i < 64; i++) {
        dst[i] = temp_dst[i];
    }
}
