#include <stdio.h>

#include <inttypes.h>

typedef struct {
    int piece;
    int square;
} see_data;

extern int board[144];
extern see_data see_attackers[2][16];
extern int square;
extern  int rook_o[4];
extern int a_sq;
extern int b_sq;
extern int i;
extern int numw;
extern int numb;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 4; i++) {
        a_sq = square + rook_o[i];
        b_sq = board[a_sq];
        if (b_sq == 5) {
            see_attackers[0][numw].piece = b_sq;
            see_attackers[0][numw].square = a_sq;
            numw++;
            break;
        } else if (b_sq == 6) {
            see_attackers[1][numb].piece = b_sq;
            see_attackers[1][numb].square = a_sq;
            numb++;
            break;
        } else if (b_sq != 0) {
            int temp_sq = a_sq;
            int temp_bsq = b_sq;
            for (; temp_bsq != 0;) {
                if (temp_bsq == 7 || temp_bsq == 9) {
                    see_attackers[0][numw].piece = temp_bsq;
                    see_attackers[0][numw].square = temp_sq;
                    numw++;
                    break;
                } else if (temp_bsq == 8 || temp_bsq == 10) {
                    see_attackers[1][numb].piece = temp_bsq;
                    see_attackers[1][numb].square = temp_sq;
                    numb++;
                    break;
                } else if (temp_bsq != 13) {
                    break;
                }
                temp_sq += rook_o[i];
                temp_bsq = board[temp_sq];
            }
        }
    }
}
