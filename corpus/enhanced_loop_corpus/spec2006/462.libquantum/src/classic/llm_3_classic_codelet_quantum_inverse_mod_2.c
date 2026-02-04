#include <stdio.h>

#include <inttypes.h>

extern int n;
extern int c;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Consecutive memory access pattern with auxiliary array to simulate data dependency
    int *buffer = (int*)__builtin_alloca(n * sizeof(int));
    // Initialize buffer to enforce consecutive access
    for (int j = 0; j < n; j++) {
        buffer[j] = 0;
    }
    for (i = 1; buffer[(i * c) % n] != 1; i++) {
        // Traverse consecutively but update at modular index
        int idx = (i * c) % n;
        buffer[idx] = (idx == 1) ? 1 : 0;
    }
}
