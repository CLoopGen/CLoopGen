#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int ni;
extern int *left;
extern int *right;
extern int *weight;
extern int i;
extern int j;
extern int jh;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index remapping array (simulated via arithmetic)
    // Assume logical indirect indexing: use (i * 3) % ni to simulate non-consecutive access
    for (i = 1; i < ni; ++i) {
        int idx = (i * 3) % ni;  // Indirect-like access pattern
        if (left[idx] <= right[idx]) {
            weight[j] = right[idx] - left[idx] + 1;
            jh = left[idx] + weight[j] / 2;
            ++j;
        }
    }
}
