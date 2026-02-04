#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int square;
extern int l;
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Consecutive array access using a derived index array (simulated indirect pattern)
    int base_index = square - 11;
    int stride = -11;
    int indices[16];  // Assume maximum reasonable iterations
    // Precompute access pattern (indirect-like access via consecutive traversal of index list)
    for (int i = 0; i < 16; i++) {
        indices[i] = base_index + i * stride;
    }
    // Traverse using consecutive access over precomputed indices
    for (int i = 0; board[indices[i]] == 13; i++) {
        m++;
        l = indices[i] - 11;  // Update l to next expected value
        if (i == 15) break;  // Prevent overflow
    }
}
