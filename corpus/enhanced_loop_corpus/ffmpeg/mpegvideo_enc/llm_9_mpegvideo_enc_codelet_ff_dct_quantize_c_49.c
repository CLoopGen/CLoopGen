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
    // Variant 2: Reduced arithmetic operations and simplified control flow with increased trip count precision
    for (i = 63; i >= start_i; i--) {
        j = scantable[i];
        level = block[j] * qmat[j]; // Single multiplication only

        // Replace compound condition with direct comparison to reduce complexity
        if (level > (int)(threshold2 - threshold1)) {
            last_non_zero = i;
            break;
        } else {
            block[j] = 0;
        }
        
        // Add minimal computational overhead per iteration to simulate cache effects
        threshold1 += (threshold1 & 1); // Tiny side-effect operation
    }
}
