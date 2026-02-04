#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern char active[400];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of sequential k increment, use a stride of 2 to access board and active arrays,
    // then handle remaining indices in a second pass with offset. This creates a strided access pattern.
    int stride = 2;
    int start = 19 + 2;
    int end = (19 + 1) * (19 + 1);

    // First pass: even-like indices (conceptually strided)
    for (k = start; k < end; k += stride) {
        if (!(board[k] != 3))
            continue;
        if (active[k] != 0)
            continue;
        if (((board[k + (19 + 1)] != 3) && active[k + (19 + 1)] > 0 && active[k + (19 + 1)] < 4) ||
            ((board[k - 1] != 3) && active[k - 1] > 0 && active[k - 1] < 4) ||
            ((board[k - (19 + 1)] != 3) && active[k - (19 + 1)] > 0 && active[k - (19 + 1)] < 4) ||
            ((board[k + 1] != 3) && active[k + 1] > 0 && active[k + 1] < 4))
            active[k] = 4;
    }

    // Second pass: odd-like indices (fill in the stride gaps)
    for (k = start + 1; k < end; k += stride) {
        if (!(board[k] != 3))
            continue;
        if (active[k] != 0)
            continue;
        if (((board[k + (19 + 1)] != 3) && active[k + (19 + 1)] > 0 && active[k + (19 + 1)] < 4) ||
            ((board[k - 1] != 3) && active[k - 1] > 0 && active[k - 1] < 4) ||
            ((board[k - (19 + 1)] != 3) && active[k - (19 + 1)] > 0 && active[k - (19 + 1)] < 4) ||
            ((board[k + 1] != 3) && active[k + 1] > 0 && active[k + 1] < 4))
            active[k] = 4;
    }
}
