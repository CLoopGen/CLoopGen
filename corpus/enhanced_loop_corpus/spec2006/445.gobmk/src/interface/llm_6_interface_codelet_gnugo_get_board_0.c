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
    int ii, jj;
    for (ii = 0; ii < board_size; ii++) {
        for (jj = 0; jj < board_size; jj++) {
            b[ii][jj] = board[((19 + 2) + (ii) * (19 + 1) + (jj))];
        }
    }
}
