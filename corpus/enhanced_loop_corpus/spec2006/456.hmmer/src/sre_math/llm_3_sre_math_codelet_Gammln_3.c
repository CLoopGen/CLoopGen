#include <stdio.h>

#include <inttypes.h>

extern int i;
extern double tmp;
extern double value;
extern double cof[11];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index remapping array
    // Simulate indirect access via a predefined permutation of indices
    int order[11] = {0, 2, 4, 6, 8, 10, 9, 7, 5, 3, 1}; // Example non-sequential access pattern
    double step = 1.0;
    for (i = 10; i >= 0; i--) {
        int idx = order[10 - i]; // Map loop index to indirect access
        value += cof[idx] / tmp;
        tmp -= step;
    }
}
