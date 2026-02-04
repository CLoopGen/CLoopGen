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
    int temp_attackers = 0;
    int a_sq_local[4];
    for (i = 0; i < 4; i++) {
        a_sq_local[i] = square + bishop_o[i];
        int val = board[a_sq_local[i]];
        if (val == 2 && !(i % 2)) {
            temp_attackers++;
        } else if (val == 6) {
            temp_attackers++;
        } else if (val != 0) {
            int next_sq = a_sq_local[i] + bishop_o[i];
            int step_val = board[next_sq];
            if (step_val == 12 || step_val == 10) {
                temp_attackers++;
            } else if (step_val != 13) {
                // No increment, dependency broken early
            }
        }
    }
    attackers += temp_attackers;
}
