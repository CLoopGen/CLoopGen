#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern int board_size;
extern Intersection board[421];
extern Intersection initial_board[421];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    Intersection temp_board[421];
    Intersection temp_initial[421];
    for (int i = 0; i < 421; i++) {
        temp_board[i] = board[i];
        temp_initial[i] = initial_board[i];
    }
    for (k = 0; k < ((19 + 2) * (19 + 1) + 1); k++) {
        if (!((unsigned int)(((k) / (19 + 1) - 1)) < (unsigned int)board_size && (unsigned int)(((k) % (19 + 1) - 1)) < (unsigned int)board_size)) {
            temp_board[k] = 3;
            temp_initial[k] = 3;
        }
    }
    for (k = 0; k < ((19 + 2) * (19 + 1) + 1); k++) {
        board[k] = temp_board[k];
        initial_board[k] = temp_initial[k];
    }
}
