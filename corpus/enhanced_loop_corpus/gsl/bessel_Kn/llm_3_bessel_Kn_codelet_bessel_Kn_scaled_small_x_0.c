#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int n;
extern int k;
extern double y;
extern double k_term;
extern double sum1;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect access pattern simulation via precomputed index table
    // We create a local array of valid indices (1 to n-1), then iterate over them indirectly
    // This models indirect memory access patterns common in sparse computations

    if (n <= 1) return;

    int size = n - 1;
    int *indices = (int*)malloc(size * sizeof(int));
    if (!indices) return; // Handle allocation failure

    // Precompute index sequence (could be shuffled or reordered in real indirect access)
    for (int i = 0; i < size; i++) {
        indices[i] = i + 1;
    }

    // Traverse indices indirectly
    for (int idx = 0; idx < size; idx++) {
        k = indices[idx];
        k_term *= -y / (k * (n - k));
        sum1 += k_term;
    }

    free(indices);
}
