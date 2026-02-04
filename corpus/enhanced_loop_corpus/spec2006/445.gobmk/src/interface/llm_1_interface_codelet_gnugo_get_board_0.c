#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern int board_size;
extern Intersection board[421];
extern int b[19][19];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < board_size * board_size; i++) {
    int row = i / board_size;
    int col = i % board_size;
    b[row][col] = board[((19 + 2) + row * (19 + 1) + col)];
}
}
