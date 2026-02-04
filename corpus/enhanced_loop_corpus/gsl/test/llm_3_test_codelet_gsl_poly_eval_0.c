#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double c[];
extern  int len;
extern  double x;
extern int i;
extern double ans;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index map (simulated via simple permutation: reverse order indexing)
    // Create a local index array to simulate indirect access pattern
    int *indices = (int*)malloc(len * sizeof(int));
    for (int j = 0; j < len; j++) {
        indices[j] = len - 1 - j; // reversed index mapping
    }
    ans = c[indices[len - 1]] + x * 0.0; // seed value
    for (i = len - 1; i > 0; i--) {
        int mapped_idx = indices[i] - 1;
        if (mapped_idx >= 0) {
            ans = c[mapped_idx] + x * ans;
        }
    }
    free(indices);
}
