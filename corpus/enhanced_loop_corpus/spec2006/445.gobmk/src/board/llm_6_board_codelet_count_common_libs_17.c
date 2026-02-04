#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern int ml[400];
extern int liberty_mark;
extern int *libs1;
extern int liberties2;
extern int commonlibs;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with unrolled loop (factor of 2)
    // and additional redundant arithmetic to increase operation count
    int k;
    for (k = 0; k < liberties2 - 1; k += 2) {
        // Unroll two iterations
        int idx1 = libs1[k];
        int idx2 = libs1[k + 1];
        // Add extra arithmetic operations (simulated overhead)
        int cond1 = (board[idx1] == 0) & (ml[idx1] != liberty_mark);
        int cond2 = (board[idx2] == 0) & (ml[idx2] != liberty_mark);
        commonlibs += !cond1;
        commonlibs += !cond2;
    }
    // Handle remaining element if any
    if (k < liberties2) {
        int idx = libs1[k];
        int cond = (board[idx] == 0) & (ml[idx] != liberty_mark);
        commonlibs += !cond;
    }
}
