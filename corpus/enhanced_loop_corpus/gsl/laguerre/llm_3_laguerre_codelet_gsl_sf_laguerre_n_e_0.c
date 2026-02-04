#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int n;
extern  double a;
extern double product;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect access pattern via index remapping using a lookup table for iteration order
    // We create an auxiliary index array that defines a non-consecutive access pattern,
    // simulating indirect or randomized traversal relevant in certain optimized algorithms.
    
    if (n < 2) return;

    int *indices = (int*)malloc((n - 1) * sizeof(int));
    double temp_product = product;

    // Fill indices with sequential values: [2, 3, ..., n]
    for (int i = 0; i < n - 1; i++) {
        indices[i] = i + 2;
    }

    // Process in reverse order to simulate indirect/non-sequential access pattern
    for (int i = n - 2; i >= 0; i--) {
        int k = indices[i];
        temp_product *= (a + k) / k;
    }

    product = temp_product;
    free(indices);
}
