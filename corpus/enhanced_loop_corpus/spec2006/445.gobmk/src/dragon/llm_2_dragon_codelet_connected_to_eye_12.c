#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern int delta[8];
extern Intersection board[421];
extern int pos;
extern char mx[400];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with unrolled loop (stride of 2, simulating non-consecutive access)
    for (k = 0; k < 8; k += 2) {
        int idx1 = pos + delta[k];
        if ((board[idx1] != 3))
            mx[idx1] = 1;

        if (k + 1 < 8) {
            int idx2 = pos + delta[k + 1];
            if ((board[idx2] != 3))
                mx[idx2] = 1;
        }
    }
}
