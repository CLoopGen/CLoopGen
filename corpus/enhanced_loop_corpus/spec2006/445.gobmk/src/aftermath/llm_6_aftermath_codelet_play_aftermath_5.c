#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern int pos;
extern int current_board[400];
extern int cached_board;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_board[400];
    for (int i = 0; i < 400; i++) {
        temp_board[i] = current_board[i];
    }
    for (pos = (19 + 2); pos < (19 + 1) * (19 + 1); pos++) {
        if ((board[pos] != 3) && board[pos] != temp_board[pos]) {
            current_board[pos] = board[pos];
            cached_board = 0;
        }
    }
}
