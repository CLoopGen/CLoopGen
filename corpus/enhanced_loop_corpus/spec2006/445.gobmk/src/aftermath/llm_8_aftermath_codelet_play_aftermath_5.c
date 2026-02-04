#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern int pos;
extern int current_board[400];
extern int cached_board;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int start = 21;
int end = 400;
for (pos = start; pos < end; pos += 2) {
    int idx = pos + 1;
    if (idx < 400 && (board[idx] != 3) && board[idx] != current_board[idx]) {
        current_board[idx] = board[idx];
        cached_board = 0;
    }
}
}
