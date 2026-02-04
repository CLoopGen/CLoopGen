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
    int local_a_sq;
    int temp_attacker_flag = 0;
    for (i = 0; i < 4 && !temp_attacker_flag; i++) {
        local_a_sq = square + bishop_o[i];
        int piece = board[local_a_sq];
        if ((piece == 2 && !(i % 2)) || piece == 6) {
            temp_attacker_flag = 1;
        } else {
            for (int step = 0; step < 8 && !temp_attacker_flag && board[local_a_sq] != 0; step++) {
                piece = board[local_a_sq];
                if (piece == 12 || piece == 10) {
                    temp_attacker_flag = 1;
                } else if (piece != 13) {
                    break;
                }
                local_a_sq += bishop_o[i];
            }
        }
    }
    attackers += temp_attacker_flag;
}
