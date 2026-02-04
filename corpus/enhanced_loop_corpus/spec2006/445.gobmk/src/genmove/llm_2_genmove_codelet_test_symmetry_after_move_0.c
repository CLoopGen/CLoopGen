#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern int board_size;
extern Intersection board[421];
extern int pos;
extern int result;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access with Precomputed Indices
    int start = (19 + 2);
    int end = (19 + 2) + (board_size - 1 - ((start) / (19 + 1) - 1)) * (19 + 1) + (board_size - 1 - ((start) % (19 + 1) - 1));
    int stride = (19 + 1);
    int base_row = (board_size - 1 - ((start) / stride - 1));
    int base_col = (board_size - 1 - ((start) % stride - 1));
    
    for (pos = start; pos <= end; pos++) {
        int mirror_pos = (19 + 2) + base_row * stride + base_col - (pos - start);
        if ((board[pos] == 0) ^ (board[mirror_pos] == 0)) {
            result = 0;
            break;
        }
    }
}
