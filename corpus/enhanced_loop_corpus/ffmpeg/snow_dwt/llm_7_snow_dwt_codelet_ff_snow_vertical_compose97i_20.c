#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef short IDWTELEM;

extern IDWTELEM *b0;
extern IDWTELEM *b1;
extern IDWTELEM *b2;
extern IDWTELEM *b3;
extern IDWTELEM *b4;
extern IDWTELEM *b5;
extern int width;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < width; i++) {
        // Reorder statements to introduce loop-carried dependency on b1[i-1]
        // and fuse operations to create combined update patterns.
        // This variant introduces a RAW dependency across iterations via b1_prev.
        IDWTELEM b1_prev = (i > 0) ? b1[i - 1] : 0;
        b2[i] += (1 * (b1[i] + b3[i]) + 4 * b2[i] + 8) >> 4;
        b3[i] -= (1 * (b2[i] + b4[i]) + 0) >> 0;
        b4[i] -= (3 * (b3[i] + b5[i]) + 4) >> 3;
        b1[i] += (3 * (b0[i] + b2[i]) + b1_prev) >> 1;  // Added dependence on previous b1
    }
}
