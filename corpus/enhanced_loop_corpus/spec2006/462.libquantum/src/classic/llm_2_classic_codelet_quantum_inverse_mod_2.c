#include <stdio.h>

#include <inttypes.h>

extern int n;
extern int c;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access pattern simulation using an array-like indexing with stride
    int *dummy_array = (int*)__builtin_alloca(n * sizeof(int));
    for (i = 1; i < n; i++) {
        // Simulate strided access: every c-th element modulo n
        int idx = (i * c) % n;
        dummy_array[idx] = i;  // Write to strided location
        if (idx == 1) break;
    }
}
