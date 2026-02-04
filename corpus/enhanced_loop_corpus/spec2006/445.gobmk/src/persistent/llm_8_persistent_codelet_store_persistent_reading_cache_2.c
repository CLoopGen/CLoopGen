#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern char active[400];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int i;
for (k = 0; k < 400; k += 2) {
    for (i = 0; i < 3; i++) {  // Increased computational intensity with inner loop
        int idx = k + i;
        if (idx >= 400) break;
        if (((board[idx]) == 1 || (board[idx]) == 2) || active[idx] != 0)
            continue;
        if ((board[(idx) + 20] == 0 && active[(idx) + 20] == 2) ||
            (board[(idx) - 1] == 0 && active[(idx) - 1] == 2 && (idx - 1) >= 0) ||
            (board[(idx) - 20] == 0 && active[(idx) - 20] == 2) ||
            (board[(idx) + 1] == 0 && active[(idx) + 1] == 2 && (idx + 1) < 400))
            active[idx] = 3;
    }
}
}
