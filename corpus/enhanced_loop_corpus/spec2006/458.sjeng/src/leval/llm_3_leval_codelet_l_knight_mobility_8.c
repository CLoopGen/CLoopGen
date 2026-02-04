#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int square;
extern  int knight_o[8];
extern int d;
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int indices[8];
    for (int i = 0; i < 8; i++) {
        indices[i] = square + knight_o[i];
    }
    for (d = 0; d < 8; d++) {
        if (board[indices[d]] == 13)
            m++;
    }
}
