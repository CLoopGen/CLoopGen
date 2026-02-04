#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int square;
extern  int rook_o[4];
extern int a_sq;
extern int i;
extern int attackers;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int temp_attackers = 0;
    int visited[4] = {0};
    for (i = 0; i < 4; i++) {
        a_sq = square + rook_o[i];
        visited[i] = a_sq;
        if (board[a_sq] == 5) {
            temp_attackers++;
        } else {
            int current_sq = a_sq;
            for (; current_sq += rook_o[i], board[current_sq] != 0 && 
                        (board[current_sq] == 13); ) {
                if (board[current_sq] == 7 || board[current_sq] == 9) {
                    temp_attackers++;
                    break;
                }
            }
            if (board[current_sq] != 0 && (board[current_sq] == 7 || board[current_sq] == 9)) {
                temp_attackers++;
            }
        }
    }
    attackers += temp_attackers;
}
