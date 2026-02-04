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
for (i = 0; i < 8; i++) {
    int temp = square + knight_o[i];
    for (int k = 0; k < 1; k++) {
        a_sq = temp;
        if (board[a_sq] == 4)
            attackers++;
    }
}
}
