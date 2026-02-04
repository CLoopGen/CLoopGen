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
    // Outer loop split: process even indices first, then odd indices in separate passes
    // This increases loop nesting depth by introducing two sequential outer loops

    // First pass: even i values within [start_i, last_non_zero]
    for (int pass = 0; pass < 2; pass++) {
        for (i = start_i + pass; i <= last_non_zero; i += 2) {
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
}
