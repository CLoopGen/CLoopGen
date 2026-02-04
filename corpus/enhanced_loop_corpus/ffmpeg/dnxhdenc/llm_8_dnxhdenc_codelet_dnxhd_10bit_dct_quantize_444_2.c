#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *block;
extern int i;
extern int j;
extern int level;
extern int last_non_zero;
extern int start_i;
extern  int *qmat;
extern  uint8_t *scantable;
extern int bias;
extern int max;
extern unsigned int threshold1;
extern unsigned int threshold2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity by unrolling the loop and increasing arithmetic operations.
    // Loop unroll factor of 2 with additional redundant calculations to increase computational load.
    int i_end = last_non_zero - (last_non_zero - start_i + 1) % 2;  // Align to unroll factor
    for (i = start_i; i <= i_end; i += 2) {
        int j1 = scantable[i];
        int j2 = scantable[i+1];
        
        int level1 = block[j1] * qmat[j1];
        int level2 = block[j2] * qmat[j2];

        // Introduce extra arithmetic: simulate soft thresholding with extra shifts and masks
        unsigned int test1 = (unsigned int)(level1 + threshold1);
        unsigned int test2 = (unsigned int)(level2 + threshold1);

        if (test1 > threshold2) {
            int adjusted = (level1 > 0) ? ((bias + level1) >> 16) : ((bias - level1) >> 16);
            block[j1] = (level1 > 0) ? adjusted : -adjusted;
            max |= (adjusted & 0xFFFF);  // Mask to add complexity
        } else {
            block[j1] = 0;
        }

        if (test2 > threshold2) {
            int temp_bias = bias << 1;  // Artificially increase bias effect
            int adjusted = (level2 > 0) ? ((temp_bias + level2) >> 17) : ((temp_bias - level2) >> 17);
            adjusted = (adjusted + 1) >> 1;  // Additional averaging step
            block[j2] = (level2 > 0) ? adjusted : -adjusted;
            max |= (adjusted & 0xFFFF);
        } else {
            block[j2] = 0;
        }
    }

    // Handle remaining iteration if any
    if (i <= last_non_zero) {
        j = scantable[i];
        level = block[j] * qmat[j];
        if (((unsigned int)(level + threshold1)) > threshold2) {
            if (level > 0) {
                level = (bias + level) >> 16;
                block[j] = level;
            } else {
                level = (bias - level) >> 16;
                block[j] = -level;
            }
            max |= level;
        } else {
            block[j] = 0;
        }
    }
}
