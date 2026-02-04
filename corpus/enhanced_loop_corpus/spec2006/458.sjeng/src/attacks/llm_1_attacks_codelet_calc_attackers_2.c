#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int square;
extern  int knight_o[8];
extern int a_sq;
extern int i;
extern int attackers;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 4; i++) {
        a_sq = square + knight_o[i];
        if (board[a_sq] == 3)
            attackers++;
    }
    for (i = 4; i < 8; i++) {
        a_sq = square + knight_o[i];
        if (board[a_sq] == 3)
            attackers++;
    }
}
