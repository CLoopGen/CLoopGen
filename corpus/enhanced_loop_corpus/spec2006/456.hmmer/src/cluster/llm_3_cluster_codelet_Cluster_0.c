#include <stdio.h>

#include <inttypes.h>

extern int N;
extern int *coord;
extern int col;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index map (simulated via reverse order write)
    // We simulate indirect access by writing values in reverse index order
    for (col = 0; col < N; col++) {
        int idx = N - 1 - col; // Reverse indexing for indirect-like access pattern
        coord[idx] = idx;
    }
}
