#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int m;
extern int n;
extern double res[256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated with stride-like pattern via lookup)
    int idx[256];
    for (int i = 0; i <= n; i++) {
        idx[i] = (i * 3) % (n + 1); // Generate non-consecutive indirect indices
    }
    for (m = 1; m <= n; m++) {
        int current = idx[m];
        int prev = idx[m - 1];
        if (current < 256 && prev < 256 && prev >= 0) {
            res[current] = res[prev] / 2.;
        }
    }
}
