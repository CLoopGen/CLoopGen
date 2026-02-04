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
    // Outer loop split: process two iterations at a time to reduce effective loop depth in terms of logical steps
    int step = 2;
    for (i = start_i; i <= last_non_zero; i += step) {
        // Handle up to two elements per outer iteration
        for (int offset = 0; offset < step && (i + offset) <= last_non_zero; offset++) {
            int idx = i + offset;
            j = scantable[idx];
            level = block[j] * qmat[j];
            if (((unsigned int)(level + threshold1)) > threshold2) {
                if (level > 0) {
                    level = (bias + level) >> 21;
                    block[j] = level;
                } else {
                    level = (bias - level) >> 21;
                    block[j] = -level;
                }
                max |= level;
            } else {
                block[j] = 0;
            }
        }
    }
}
