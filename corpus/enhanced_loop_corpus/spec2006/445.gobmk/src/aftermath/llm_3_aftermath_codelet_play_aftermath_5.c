#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern int pos;
extern int current_board[400];
extern int cached_board;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using a precomputed index map
    // Simulate indirect access via an array of valid indices within the original range
    int indices[400];
    int count = 0;
    int start = (19 + 2);
    int end = (19 + 1) * (19 + 1);
    // Precompute access indices (same as sequential here, but pattern allows arbitrary reordering)
    for (int i = start; i < end; i++) {
        indices[count++] = i;
    }
    // Traverse using indirect addressing
    for (int idx = 0; idx < count; idx++) {
        int p = indices[idx]; // Actual index into arrays
        if ((board[p] != 3) && board[p] != current_board[p]) {
            current_board[p] = board[p];
            cached_board = 0;
        }
    }
}
