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
    attackers = 0;
    for (i = 0; i < 2; i++) {
        int offsets[2] = {rook_o[i], rook_o[i + 2]};
        for (int j = 0; j < 2; j++) {
            a_sq = square + offsets[j];
            if (board[a_sq] == 5) {
                attackers++;
            } else if (board[a_sq] != 0 && (board[a_sq] == 13)) {
                a_sq += offsets[j];
                if (board[a_sq] == 7 || board[a_sq] == 9) {
                    attackers++;
                }
            }
        }
    }
}
