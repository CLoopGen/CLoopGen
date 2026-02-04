#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int square;
extern  int bishop_o[4];
extern int a_sq;
extern int i;
extern int attackers;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int temp_attackers = 0;
    for (i = 0; i < 4; i++) {
        a_sq = square + bishop_o[i];
        if (board[a_sq] == 1 && (i % 2)) {
            temp_attackers++;
        } else if (board[a_sq] == 5) {
            temp_attackers++;
        } else {
            int step = bishop_o[i];
            int next_sq = a_sq + step;
            for (; next_sq < 144 && next_sq >= 0; next_sq += step) {
                if (board[next_sq] == 11 || board[next_sq] == 9) {
                    temp_attackers++;
                    break;
                } else if (board[next_sq] != 13) {
                    break;
                }
            }
        }
    }
    attackers += temp_attackers;
}
