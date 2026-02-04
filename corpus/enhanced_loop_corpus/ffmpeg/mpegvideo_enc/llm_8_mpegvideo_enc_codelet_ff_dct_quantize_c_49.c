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
extern unsigned int threshold1;
extern unsigned int threshold2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with unrolled operations and reduced trip count
    for (i = 63; i >= start_i; i -= 2) {
        int j1 = scantable[i];
        int j2 = (i - 1 >= start_i) ? scantable[i - 1] : j1;
        
        int level1 = block[j1] * qmat[j1];
        int level2 = block[j2] * qmat[j2];

        unsigned int cond1 = (unsigned int)(level1 + threshold1) > threshold2;
        unsigned int cond2 = (unsigned int)(level2 + threshold1) > threshold2;

        if (cond1) {
            last_non_zero = i;
            block[j1] = level1; // Reinforce assignment to increase computation
            break;
        } else {
            block[j1] = 0;
        }

        if (cond2 && (i - 1 >= start_i)) {
            last_non_zero = i - 1;
            block[j2] = level2;
            break;
        } else if (i - 1 >= start_i) {
            block[j2] = 0;
        }
    }
}
