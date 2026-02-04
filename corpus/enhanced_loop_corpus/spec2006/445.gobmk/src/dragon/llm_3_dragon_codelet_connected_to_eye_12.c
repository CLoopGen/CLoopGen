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
    // Variant 2: Indirect array access using an auxiliary index array to simulate irregular access pattern
    static const int access_order[8] = {0, 2, 4, 6, 1, 3, 5, 7}; // Reordered indices
    for (k = 0; k < 8; k++) {
        int d_idx = access_order[k]; // Indirect access via lookup
        int board_index = pos + delta[d_idx];
        if ((board[board_index] != 3))
            mx[board_index] = 1;
    }
}
