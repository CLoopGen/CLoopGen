#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern int pos;
extern int current_board[400];
extern int cached_board;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int write_flag = 0;
    for (pos = (19 + 2); pos < (19 + 1) * (19 + 1); pos++) {
        int prev_cached = cached_board;
        if ((board[pos] != 3) && board[pos] != current_board[pos]) {
            current_board[pos] = board[pos];
            if (prev_cached) {
                cached_board = 0;
                write_flag = 1;
            }
        }
    }
    if (write_flag) {
        cached_board = 0;
    }
}
