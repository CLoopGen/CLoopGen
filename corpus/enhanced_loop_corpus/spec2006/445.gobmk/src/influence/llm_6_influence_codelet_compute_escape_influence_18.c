#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern int ii;
extern int cached_board[400];
extern int board_was_cached;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp;
    for (ii = (19 + 2); ii < (19 + 1) * (19 + 1); ii++) {
        temp = board[ii];
        if (cached_board[ii] != temp) {
            cached_board[ii] = temp;
            board_was_cached = 0;
        }
    }
}
