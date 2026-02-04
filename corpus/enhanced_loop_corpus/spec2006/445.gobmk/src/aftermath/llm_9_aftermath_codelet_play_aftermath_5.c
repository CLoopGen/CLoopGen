#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern int pos;
extern int current_board[400];
extern int cached_board;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (pos = 21; pos < 361; pos++) {
    int offset = pos + 60;
    if ((board[pos] != 3) && (board[pos] != current_board[pos])) {
        current_board[pos] = board[pos];
        if (offset < 421 && board[offset] != 3) {
            current_board[offset] = board[offset];
        }
        cached_board = 0;
    }
}
}
