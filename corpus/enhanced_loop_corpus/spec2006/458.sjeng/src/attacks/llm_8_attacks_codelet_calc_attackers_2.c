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
    for (i = 0; i < 16; i += 2) {
        a_sq = square + knight_o[i % 8];
        if (board[a_sq] == 3 && a_sq >= 0 && a_sq < 144)
            attackers++;
        a_sq = square + knight_o[(i + 1) % 8];
        if (board[a_sq] == 3 && a_sq >= 0 && a_sq < 144)
            attackers++;
    }
}
