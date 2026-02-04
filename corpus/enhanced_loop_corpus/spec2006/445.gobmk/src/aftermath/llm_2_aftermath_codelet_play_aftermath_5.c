#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern int pos;
extern int current_board[400];
extern int cached_board;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with increased stride for board and current_board
    // Access every 2nd element starting from initial position to demonstrate strided pattern
    int start = (19 + 2);
    int end = (19 + 1) * (19 + 1);
    for (pos = start; pos < end; pos += 2) {
        if ((board[pos] != 3) && board[pos] != current_board[pos]) {
            current_board[pos] = board[pos];
            cached_board = 0;
        }
        // Handle next index if within bounds to maintain coverage
        if (pos + 1 < end) {
            if ((board[pos + 1] != 3) && board[pos + 1] != current_board[pos + 1]) {
                current_board[pos + 1] = board[pos + 1];
                cached_board = 0;
            }
        }
    }
}
