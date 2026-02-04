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
    for (i = 0; i < 8; i += 2) {
        a_sq = square + bishop_o[i % 4];
        if (board[a_sq] == 2) {
            attackers++;
            break;
        } else if (board[a_sq] == 6) {
            attackers++;
            break;
        } else {
            int step = bishop_o[i % 4];
            for (int j = 0; j < 8 && board[a_sq] != 0; j++) {
                if (board[a_sq] == 12 || board[a_sq] == 10) {
                    attackers++;
                    goto exit_loop;
                } else if (board[a_sq] != 13) {
                    break;
                }
                a_sq += step;
            }
        }
    }
    return;
exit_loop:
    return;
}
