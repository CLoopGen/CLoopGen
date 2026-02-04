#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double w87a[21];
extern double savfun[21];
extern double res87;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect (gather) memory access using an index map
    // Simulates non-sequential access via an explicit index array
    int idx[21];
    for (int i = 0; i < 21; i++) {
        idx[i] = i;
    }
    res87 = 0.0;
    // Shuffle indices in a realistic but altered access pattern: reverse order
    for (int i = 0; i < 21; i++) {
        int j = 20 - i;  // reverse mapping
        res87 += savfun[idx[j]] * w87a[idx[j]];
    }
}
