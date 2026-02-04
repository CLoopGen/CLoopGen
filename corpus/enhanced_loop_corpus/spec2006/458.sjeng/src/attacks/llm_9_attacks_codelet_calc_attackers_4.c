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
    attackers = 0;
    const int offsets[] = {bishop_o[0], bishop_o[1], bishop_o[2], bishop_o[3]};
    for (i = 0; i < 4; i++) {
        a_sq = square + offsets[i];
        int piece = board[a_sq];
        if ((piece == 2 && !(i & 1)) || piece == 6) {
            attackers = 1;
            break;
        }
        if (piece == 12 || piece == 10) {
            attackers = 1;
            break;
        }
        if (piece == 13) {
            a_sq += offsets[i];
            if (a_sq < 144 && a_sq >= 0) {
                piece = board[a_sq];
                if (piece == 12 || piece == 10) {
                    attackers = 1;
                    break;
                }
            }
        }
    }
}
