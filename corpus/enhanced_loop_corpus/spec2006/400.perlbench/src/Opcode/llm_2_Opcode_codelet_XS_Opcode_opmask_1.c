#include <stdio.h>

#include <inttypes.h>

extern char *PL_op_mask;
extern int PL_maxo;
extern char *bitmap;
extern int myopcode;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with reversed iteration and unrolling by 2
    int i;
    for (i = PL_maxo - 1; i >= 0; i -= 2) {
        int idx1 = i;
        if (idx1 < PL_maxo && PL_op_mask[idx1])
            bitmap[idx1 >> 3] |= 1 << (idx1 & 7);
        
        if (i - 1 >= 0) {
            int idx2 = i - 1;
            if (PL_op_mask[idx2])
                bitmap[idx2 >> 3] |= 1 << (idx2 & 7);
        }
    }
}
