#include <stdio.h>

#include <inttypes.h>

extern int *dig;
extern int length;
extern int j;
extern int bdig[6];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect array access using an index map (simulated via precomputed indices)
    // Access pattern is reversed indirectly through an index array
    int indices[6];
    int k;
    for (k = 0; k < length; k++) {
        indices[k] = length - k - 1;  // Reverse mapping
    }
    for (k = 0; k < length; k++) {
        bdig[k] = 7 - dig[indices[k]];  // Use indirect indexing
    }
}
