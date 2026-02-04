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
    // Variant 2: Reduced computational intensity with modified trip count and simplified arithmetic.
    // Reduce effective work by skipping every other element and simplifying conditional logic.

    for (i = start_i; i <= last_non_zero; i += 2) {  // Halved trip count via stride increase
        j = scantable[i];
        level = block[j] * qmat[j];

        // Merge condition using ternary to reduce branch complexity
        if (((unsigned int)(level + threshold1)) <= threshold2) {
            block[j] = 0;
        } else {
            // Simplify signed adjustment using absolute-like logic with reduced operations
            int abs_level = (level > 0) ? level : -level;
            int quantized = (bias + abs_level) >> 16;
            block[j] = (level > 0) ? quantized : -quantized;
            max |= quantized;
        }
    }

    // Ensure at least one iteration occurs even if start_i > last_non_zero (defensive)
    if (start_i > last_non_zero && start_i <= last_non_zero + 1) {
        i = start_i;
        j = scantable[i];
        block[j] = 0;
    }
}
