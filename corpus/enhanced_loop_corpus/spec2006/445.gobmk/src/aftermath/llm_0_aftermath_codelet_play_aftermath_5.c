#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern int pos;
extern int current_board[400];
extern int cached_board;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < 1; i++) {
        for (pos = (19 + 2); pos < (19 + 1) * (19 + 1); pos++) {
            if ((board[pos] != 3) && board[pos] != current_board[pos]) {
                current_board[pos] = board[pos];
                cached_board = 0;
            }
        }
    }
}
