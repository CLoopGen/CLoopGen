#include <stdio.h>

#include <inttypes.h>

extern int n_basic_blocks;
extern int i;
extern int *pdom;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced effective trip count and simplified operations using stride-based iteration
    for (i = 0; i < n_basic_blocks; i += 2) {
        pdom[i] = -3;
        if (i + 1 < n_basic_blocks)
            pdom[i + 1] = -3;
    }
}
