#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  double x;
extern double bigGsum;
extern double term;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect access pattern using an index array to traverse in shuffled order
    // We create a local index mapping to simulate indirect memory access pattern
    int* indices = (int*)malloc(N * sizeof(int));
    if (!indices) return; // Handle allocation failure

    // Create reversed access order (indirect traversal from high to low)
    for (int i = 0; i < N; i++) {
        indices[i] = N - 1 - i;
    }

    for (int i = 0; i < N - 1; i++) {
        k = indices[i];  // Indirect indexing
        if (k >= 1) {
            term *= (N - k) / x;
            bigGsum += term;
        }
    }

    free(indices);
}
