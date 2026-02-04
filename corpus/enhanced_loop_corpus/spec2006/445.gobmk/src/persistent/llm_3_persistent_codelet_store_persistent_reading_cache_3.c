#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern char active[400];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive (Linearized Neighbor Access) Memory Access Pattern
    // Restructure memory accesses to improve spatial locality by precomputing neighbor indices
    // and accessing memory in a more predictable, consecutive manner where possible.
    int center, up, down, left, right;
    int board_val, active_val;
    int N = 19 + 1;

    for (k = (19 + 2); k < (19 + 1) * (19 + 1); k++) {
        center = k;
        down   = center + N;
        up     = center - N;
        left   = center - 1;
        right  = center + 1;

        // Load center values once
        board_val = board[center];
        active_val = active[center];

        if (!(board_val != 3))
            continue;
        if (active_val != 0)
            continue;

        // Evaluate neighbors using precomputed indices to promote consecutive access patterns
        // and potential compiler optimization (e.g., better caching or vectorization hints).
        if (((board[down] != 3) && active[down] > 0 && active[down] < 4) ||
            ((board[left] != 3) && active[left] > 0 && active[left] < 4) ||
            ((board[up] != 3) && active[up] > 0 && active[up] < 4) ||
            ((board[right] != 3) && active[right] > 0 && active[right] < 4))
            active[center] = 4;
    }
}
