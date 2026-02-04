#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern int board_size;
extern Intersection board[421];
extern Intersection initial_board[421];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int outer = 0; outer < ((19 + 2) * (19 + 1) + 1); outer += (19 + 1)) {
    for (int k = outer; k < outer + (19 + 1) && k < ((19 + 2) * (19 + 1) + 1); k++) {
        if (!((unsigned int)(((k) / (19 + 1) - 1)) < (unsigned int)board_size && (unsigned int)(((k) % (19 + 1) - 1)) < (unsigned int)board_size)) {
            board[k] = 3;
            initial_board[k] = 3;
        }
    }
}
}
