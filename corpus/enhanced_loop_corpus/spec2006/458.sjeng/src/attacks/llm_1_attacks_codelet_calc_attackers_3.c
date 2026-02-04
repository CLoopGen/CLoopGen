#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int square;
extern  int rook_o[4];
extern int a_sq;
extern int i;
extern int attackers;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 4; i++) {
        a_sq = square + rook_o[i];
        if (board[a_sq] == 6) {
            attackers++;
        } else {
            int step = 0;
            for (; step < 20 && board[a_sq] != 0; step++) {
                if (board[a_sq] == 8 || board[a_sq] == 10) {
                    attackers++;
                    break;
                }
                if (board[a_sq] != 13) break;
                a_sq += rook_o[i];
            }
        }
    }
}
