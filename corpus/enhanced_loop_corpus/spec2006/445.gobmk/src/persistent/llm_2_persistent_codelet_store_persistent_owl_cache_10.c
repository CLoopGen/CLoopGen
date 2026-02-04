#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern char goal[400];
extern char active[400];
extern int pos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with increased stride
    // Instead of sequential access, we traverse the array with a stride of 3
    int start = 19 + 2;
    int end = (19 + 1) * (19 + 1);
    for (pos = start; pos < end; pos += 3) {
        if ((board[pos] != 3))
            active[pos] = (goal[pos] != 0);
    }
    // Handle remaining elements to maintain correctness
    for (pos = start + 1; pos < end; pos++) {
        if (pos % 3 != 0 && pos % 3 != 1) continue;
        if ((board[pos] != 3))
            active[pos] = (goal[pos] != 0);
    }
}
