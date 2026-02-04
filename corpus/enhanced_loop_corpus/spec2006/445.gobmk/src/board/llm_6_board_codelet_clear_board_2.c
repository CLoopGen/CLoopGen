#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern int board_size;
extern Intersection board[421];
extern Intersection initial_board[421];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int idx;
    for (k = 0; k < ((19 + 2) * (19 + 1) + 1); k++) {
        idx = k;
        if (!((unsigned int)((idx / (19 + 1) - 1)) < (unsigned int)board_size && (unsigned int)((idx % (19 + 1) - 1)) < (unsigned int)board_size)) {
            board[idx] = 3;
            initial_board[idx] = 3;
        }
    }
}
