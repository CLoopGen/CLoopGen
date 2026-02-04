#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern  uint8_t *block;
extern int x;
extern int y;
extern int mn;
extern int mx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced trip count with combined outer and inner loop into a single loop, lowering computational load
    // Total iterations reduced from 16 to 8 by stepping through only half the original indices
    for (int idx = 0; idx < 8; idx++) {
        int x = (idx & 1) << 1;          // x alternates between 0 and 2
        int y = (idx >> 1) & 3;          // y cycles through 0,0,1,1,2,2,3,3
        int val = block[3 + x * 4 + y * stride];
        if (val < mn)
            mn = val;
        else if (val > mx)
            mx = val;
    }
}
