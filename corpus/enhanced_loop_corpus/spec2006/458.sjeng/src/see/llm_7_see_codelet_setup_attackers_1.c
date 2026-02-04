#include <stdio.h>

#include <inttypes.h>

typedef struct {
    int piece;
    int square;
} see_data;

extern int board[144];
extern see_data see_attackers[2][16];
extern int square;
extern  int bishop_o[4];
extern int a_sq;
extern int b_sq;
extern int i;
extern int numw;
extern int numb;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_numw = numw;
    int local_numb = numb;
    int updated_flags[4] = {0};
    for (i = 0; i < 4; i++) {
        a_sq = square + bishop_o[i];
        b_sq = board[a_sq];
        if (b_sq == 1 && i % 2) {
            see_attackers[0][local_numw].piece = b_sq;
            see_attackers[0][local_numw].square = a_sq;
            local_numw++;
            updated_flags[i] = 1;
        } else if (b_sq == 2 && !(i % 2)) {
            see_attackers[1][local_numb].piece = b_sq;
            see_attackers[1][local_numb].square = a_sq;
            local_numb++;
            updated_flags[i] = 1;
        } else if (b_sq == 5) {
            see_attackers[0][local_numw].piece = b_sq;
            see_attackers[0][local_numw].square = a_sq;
            local_numw++;
            updated_flags[i] = 1;
        } else if (b_sq == 6) {
            see_attackers[1][local_numb].piece = b_sq;
            see_attackers[1][local_numb].square = a_sq;
            local_numb++;
            updated_flags[i] = 1;
        } else {
            int ray_sq = a_sq;
            int piece_val = b_sq;
            for (int step = 0; step < 8 && piece_val == 13; step++) {
                ray_sq += bishop_o[i];
                piece_val = board[ray_sq];
            }
            if (piece_val == 11 || piece_val == 9) {
                see_attackers[0][local_numw].piece = piece_val;
                see_attackers[0][local_numw].square = ray_sq;
                local_numw++;
                updated_flags[i] = 1;
            } else if (piece_val == 12 || piece_val == 10) {
                see_attackers[1][local_numb].piece = piece_val;
                see_attackers[1][local_numb].square = ray_sq;
                local_numb++;
                updated_flags[i] = 1;
            }
        }
    }
    for (int j = 0; j < 4; j++) {
        if (updated_flags[j]) {
            numw = (j % 2 == 0) ? numw : local_numw;
            numb = (j % 2 == 1) ? numb : local_numb;
            break;
        }
    }
}
