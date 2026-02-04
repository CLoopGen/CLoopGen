#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int n;
extern  double x;
extern double product;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array to access elements in non-linear order
    // Simulate indirect access by precomputing a permutation of indices
    int *indices = (int*)malloc(n * sizeof(int));
    if (!indices) return; // Handle allocation failure

    // Create a mirrored access pattern: [n, n-1, ..., 1]
    for (int j = 0; j < n; j++) {
        indices[j] = n - j;
    }

    product = 1.0; // Reset product
    for (int i = 0; i < n; i++) {
        int k_val = indices[i]; // Indirect access via index array
        product *= (x / k_val);
    }

    free(indices);
}
