#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef short IDWTELEM;

extern IDWTELEM *b0;
extern IDWTELEM *b1;
extern IDWTELEM *b2;
extern int width;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive two-element unrolling with direct indexing
    IDWTELEM *p_b0 = b0;
    IDWTELEM *p_b1 = b1;
    IDWTELEM *p_b2 = b2;

    int limit = width - (width % 2);
    for (i = 0; i < limit; i += 2) {
        p_b1[0] -= (p_b0[0] + p_b2[0] + 2) >> 2;
        p_b1[1] -= (p_b0[1] + p_b2[1] + 2) >> 2;
        p_b0 += 2;
        p_b1 += 2;
        p_b2 += 2;
    }

    // Handle remaining element if width is odd
    if (i < width) {
        b1[i] -= (b0[i] + b2[i] + 2) >> 2;
    }
}
