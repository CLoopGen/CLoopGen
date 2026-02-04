#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern int replacement_map[400];
extern int from;
extern int pos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Eliminate loop-carried dependency by unrolling and reordering independent operations
    // Assume (19+1)*(19+1) - (19+2) is divisible by 2 for simplicity
    int start = 21;
    int end = 400; // (19+1)^2 = 400
    // Process two iterations per loop step to change data access pattern
    for (pos = start; pos < end - 1; pos += 2) {
        // Process pos and pos+1 independently to reduce dependencies
        if ((board[pos] != 3) && replacement_map[pos] == from)
            replacement_map[pos] = replacement_map[from];
        if ((board[pos+1] != 3) && replacement_map[pos+1] == from)
            replacement_map[pos+1] = replacement_map[from];
    }
    // Handle odd-sized range if needed
    if (pos < end) {
        if ((board[pos] != 3) && replacement_map[pos] == from)
            replacement_map[pos] = replacement_map[from];
    }
}
