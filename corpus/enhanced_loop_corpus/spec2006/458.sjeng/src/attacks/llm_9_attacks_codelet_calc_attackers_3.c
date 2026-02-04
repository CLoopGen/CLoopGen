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
for (i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
        int index = i * 2 + j;
        a_sq = square + rook_o[index];
        int piece = board[a_sq];
        if (piece == 6 || piece == 8 || piece == 10) {
            attackers++;
            break;
        } else if (piece == 13) {
            a_sq += rook_o[index];
            piece = board[a_sq];
            if (piece == 8 || piece == 10) {
                attackers++;
            }
            break;
        }
    }
}
}
