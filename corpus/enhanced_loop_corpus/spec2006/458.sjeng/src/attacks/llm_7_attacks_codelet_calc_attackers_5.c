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
    int temp_result[8] = {0};
    for (i = 0; i < 8; i++) {
        a_sq = square + knight_o[i];
        temp_result[i] = (board[a_sq] == 4) ? 1 : 0;
    }
    for (i = 0; i < 8; i++) {
        attackers += temp_result[i];
    }
}
