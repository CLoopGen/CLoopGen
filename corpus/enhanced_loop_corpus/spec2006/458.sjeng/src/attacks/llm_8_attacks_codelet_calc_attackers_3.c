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
for (i = 0; i < 8; i += 2) {
    a_sq = square + rook_o[i % 4];
    if (board[a_sq] == 6) {
        attackers++;
    } else if (board[a_sq] != 0) {
        int next_sq = a_sq + rook_o[i % 4];
        if (board[a_sq] == 8 || board[a_sq] == 10) {
            attackers++;
        } else if (board[a_sq] == 13 && board[next_sq] != 0) {
            if (board[next_sq] == 8 || board[next_sq] == 10) {
                attackers++;
            }
        }
    }
}
}
