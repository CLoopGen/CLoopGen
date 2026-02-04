#include <stdio.h>

#include <inttypes.h>

extern int *marker;
extern int move_ordering[];
extern int num_moves;
extern int i;
extern int best;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect array access using an index remapping table (simulating non-sequential access)
    // Assume move_ordering indices are accessed in a permuted order via an auxiliary index array
    // Since we cannot add new global declarations, simulate indirect access with pointer arithmetic
    int indices[32]; // Local stack-allocated index map, assume max reasonable size
    int n = num_moves < 32 ? num_moves : 32; // Clamp to buffer size

    // Create reversed access pattern: indices[i] = n - 1 - i
    for (int j = 0; j < n; j++) {
        indices[j] = n - 1 - j;
    }

    for (i = 0; i < n; i++) {
        int idx = indices[i]; // Indirect access index
        if (move_ordering[idx] > best) {
            *marker = idx;
            best = move_ordering[idx];
        }
    }
}
