#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double a_work[8];
extern double alpha[7][7];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using index mapping array
    // Simulate indirect access via precomputed indices within valid range
    int indices[6];
    for (int i = 0; i < 6; i++) {
        indices[i] = (i * 5 + 1) % 6; // Generate non-consecutive, wrapped indices
    }
    for (k = 0; k < 6; k++) {
        int idx = indices[k];
        if (idx < 6 && (idx + 1) < 7 && a_work[idx + 2] > a_work[idx + 1] * alpha[idx][idx + 1])
            break;
    }
}
