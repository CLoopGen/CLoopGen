#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern int ml[400];
extern int liberty_mark;
extern int maxlib;
extern int *libs;
extern int *libs1;
extern int liberties2;
extern int commonlibs;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced arithmetic and conditional complexity with simplified logic flow
    // Uses direct increment and removes nested condition by pre-checking bounds
    if (maxlib <= 0) return;

    for (k = 0; k < liberties2 && commonlibs < maxlib; k++) {
        Intersection pos = board[libs1[k]];
        int mark_match = (ml[libs1[k]] == liberty_mark);
        // Combine conditions: only add if not (pos == 0 AND mark doesn't match)
        // Equivalent to: add if pos != 0 OR mark matches
        if (pos != 0 || mark_match) {
            libs[commonlibs] = libs1[k];
            commonlibs++;
        }
    }
}
