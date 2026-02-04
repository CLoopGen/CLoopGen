#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern char active[400];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of sequential k increment, use a stride of 2 to access memory in a non-consecutive pattern.
    // We maintain correctness by adjusting loop bounds and handling edge cases via conditional checks.
    int stride = 2;
    for (k = (19 + 2); k < (19 + 1) * (19 + 1); k += stride) {
        // Process current and next index if within bounds (simulate strided traversal with dual access)
        int indices[2] = {k, k + 1};
        for (int i = 0; i < 2; i++) {
            int idx = indices[i];
            if (idx >= (19 + 1) * (19 + 1)) break;
            if (((board[idx]) == 1 || (board[idx]) == 2) || active[idx] != 0)
                continue;
            if ((board[(idx) + (19 + 1)] == 0 && active[(idx) + (19 + 1)] == 2) ||
                (board[(idx) - 1] == 0 && active[(idx) - 1] == 2) ||
                (board[(idx) - (19 + 1)] == 0 && active[(idx) - (19 + 1)] == 2) ||
                (board[(idx) + 1] == 0 && active[(idx) + 1] == 2))
                active[idx] = 3;
        }
    }
}
