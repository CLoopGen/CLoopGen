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
    int local_a_sq[4];
    int local_result[4] = {0};
    for (i = 0; i < 4; i++) {
        local_a_sq[i] = square + rook_o[i];
        if (board[local_a_sq[i]] == 5) {
            local_result[i] = 1;
        } else {
            int step = rook_o[i];
            int probe = local_a_sq[i];
            for (int j = 0; j < 8; j++) {
                probe += step;
                if (board[probe] == 0) break;
                if (board[probe] == 7 || board[probe] == 9) {
                    local_result[i] = 1;
                    break;
                }
                if (board[probe] != 13) break;
            }
        }
    }
    for (i = 0; i < 4; i++) {
        attackers += local_result[i];
    }
}
