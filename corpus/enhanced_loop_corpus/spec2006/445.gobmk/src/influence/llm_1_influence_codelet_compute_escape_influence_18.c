#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern int ii;
extern int cached_board[400];
extern int board_was_cached;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int depth1 = 0; depth1 < 3; depth1++) {
    for (int depth2 = 0; depth2 < 2; depth2++) {
        for (ii = (19 + 2); ii < (19 + 1) * (19 + 1); ii++) {
            if (cached_board[ii] != board[ii]) {
                cached_board[ii] = board[ii];
                board_was_cached = 0;
            }
        }
    }
}
}
