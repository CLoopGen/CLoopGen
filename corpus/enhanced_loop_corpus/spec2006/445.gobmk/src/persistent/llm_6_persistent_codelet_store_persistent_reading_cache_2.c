#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern char active[400];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int base = 19 + 1;
    int offset;
    for (k = 21; k < base * base; k++) {
        if (((board[k]) == 1 || (board[k]) == 2) || active[k] != 0)
            continue;
        offset = k;
        // Introduce artificial loop-carried dependency via offset used across iterations
        if ((board[offset + base] == 0 && active[offset + base] == 2) ||
            (board[offset - 1] == 0 && active[offset - 1] == 2) ||
            (board[offset - base] == 0 && active[offset - base] == 2) ||
            (board[offset + 1] == 0 && active[offset + 1] == 2)) {
            active[k] = 3;
            // Create WAW dependency: write to same location in different iterations not safe
            // Also, use k as a function of prior writes indirectly through control flow
        }
    }
}
