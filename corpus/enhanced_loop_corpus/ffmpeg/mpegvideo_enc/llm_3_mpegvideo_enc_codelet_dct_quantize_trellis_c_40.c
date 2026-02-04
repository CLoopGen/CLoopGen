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



void loop() {
    // Variant 2: Strided Memory Access Pattern
    // Modify access pattern to process elements with a fixed stride (e.g., 2),
    // processing even and odd index groups separately to increase cache line utilization
    // in certain memory layouts. We split the original loop into two unrolled passes.

    // First pass: even strides within the logical range
    for (int offset = 0; offset <= 1; offset++) {
        for (int ii = start_i + offset; ii <= last_non_zero; ii += 2) {
            const int j = scantable[ii];
            int level = block[j] * qmat[j];
            if (((unsigned int)(level + threshold1)) > threshold2) {
                if (level > 0) {
                    level = (bias + level) >> 21;
                    coeff[0][ii] = level;
                    coeff[1][ii] = level - 1;
                } else {
                    level = (bias - level) >> 21;
                    coeff[0][ii] = -level;
                    coeff[1][ii] = -level + 1;
                }
                coeff_count[ii] = (level > 2) ? 2 : level;
                max |= level;
            } else {
                coeff[0][ii] = (level >> 31) | 1;
                coeff_count[ii] = 1;
            }
        }
    }
}
