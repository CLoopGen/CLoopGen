#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *block;
extern  int *qmat;
extern  uint8_t *scantable;
extern int max;
extern unsigned int threshold1;
extern unsigned int threshold2;
extern int bias;
extern int coeff[2][64];
extern int coeff_count[64];
extern int start_i;
extern int last_non_zero;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = start_i; i <= last_non_zero; i++) {
    const int j = scantable[i];
    int level = block[j] * qmat[j];
    if (((unsigned int)(level + threshold1)) > threshold2) {
        if (level > 0) {
            level = (bias + level) >> 21;
            coeff[0][i] = level;
            coeff[1][i] = level - 1;
        } else {
            level = (bias - level) >> 21;
            coeff[0][i] = -level;
            coeff[1][i] = -level + 1;
        }
        coeff_count[i] = ((level) > (2) ? (2) : (level));
        ((void)0);
        max |= level;
    } else {
        coeff[0][i] = (level >> 31) | 1;
        coeff_count[i] = 1;
    }

    // Artificially increase loop depth with an unrolled dummy inner loop for padding or alignment simulation
    for (int pad = 0; pad < 1; pad++) {
        // This does nothing but simulate deeper nesting for compiler analysis or pipeline effects
        ((void)0);
    }
}
}
