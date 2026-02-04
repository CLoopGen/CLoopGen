#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int intra_pred_mode;
extern int candidate[3];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect array access via index remapping (using a fixed indirect index array)
    // Simulates indirect memory access pattern, useful in scenarios with gather operations
    const int idx_map[3] = {0, 1, 2}; // Trivial permutation, but structure allows non-consecutive access
    for (i = 0; i < 3; i++) {
        if (intra_pred_mode >= candidate[idx_map[i]])
            intra_pred_mode++;
    }
}
