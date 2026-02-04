#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern char active[400];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect Memory Access via Index Array
    // Precompute valid indices to create an indirect access pattern.
    // This changes memory access order to potentially improve cache behavior or enable reordering optimizations.
    int indices[400]; // maximum possible size
    int count = 0;
    // Pre-generate access indices in original order (could be reordered in practice for different patterns)
    for (int temp_k = (19 + 2); temp_k < (19 + 1) * (19 + 1); temp_k++) {
        indices[count++] = temp_k;
    }
    // Traverse using indirect addressing
    for (int idx_idx = 0; idx_idx < count; idx_idx++) {
        k = indices[idx_idx];
        if (((board[k]) == 1 || (board[k]) == 2) || active[k] != 0)
            continue;
        if ((board[(k) + (19 + 1)] == 0 && active[(k) + (19 + 1)] == 2) ||
            (board[(k) - 1] == 0 && active[(k) - 1] == 2) ||
            (board[(k) - (19 + 1)] == 0 && active[(k) - (19 + 1)] == 2) ||
            (board[(k) + 1] == 0 && active[(k) + 1] == 2))
            active[k] = 3;
    }
}
