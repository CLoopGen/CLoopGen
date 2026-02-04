#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int square;
extern  int bishop_o[4];
extern int a_sq;
extern int i;
extern int attackers;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 4; i++) {
        a_sq = square + bishop_o[i];
        if (board[a_sq] == 2 && !(i % 2)) {
            attackers++;
            break;
        } else if (board[a_sq] == 6) {
            attackers++;
            break;
        } else {
            for (; board[a_sq] != 0; ) {
                if (board[a_sq] == 12 || board[a_sq] == 10) {
                    attackers++;
                    goto end_loop_1;
                } else if (board[a_sq] != 13)
                    break;
                a_sq += bishop_o[i];
            }
        }
        end_loop_1:;
    }
}
