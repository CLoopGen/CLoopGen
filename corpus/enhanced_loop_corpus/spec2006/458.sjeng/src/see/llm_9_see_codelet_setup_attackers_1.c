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
for (i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
        int index = i * 2 + j;
        a_sq = square + bishop_o[index];
        b_sq = board[a_sq];
        int is_odd_direction = index % 2;
        if (b_sq == 1 && is_odd_direction) {
            see_attackers[0][numw].piece = b_sq;
            see_attackers[0][numw].square = a_sq;
            numw++;
            goto next_direction;
        } else if (b_sq == 2 && !is_odd_direction) {
            see_attackers[1][numb].piece = b_sq;
            see_attackers[1][numb].square = a_sq;
            numb++;
            goto next_direction;
        } else if (b_sq == 5) {
            see_attackers[0][numw].piece = b_sq;
            see_attackers[0][numw].square = a_sq;
            numw++;
            goto next_direction;
        } else if (b_sq == 6) {
            see_attackers[1][numb].piece = b_sq;
            see_attackers[1][numb].square = a_sq;
            numb++;
            goto next_direction;
        } else {
            int temp_sq = a_sq;
            int temp_bsq = b_sq;
            for (int k = 0; k < 8; k++) {
                if (temp_bsq == 11 || temp_bsq == 9) {
                    see_attackers[0][numw].piece = temp_bsq;
                    see_attackers[0][numw].square = temp_sq;
                    numw++;
                    break;
                } else if (temp_bsq == 12 || temp_bsq == 10) {
                    see_attackers[1][numb].piece = temp_bsq;
                    see_attackers[1][numb].square = temp_sq;
                    numb++;
                    break;
                } else if (temp_bsq != 13 || temp_bsq == 0) {
                    break;
                }
                temp_sq += bishop_o[index];
                temp_bsq = board[temp_sq];
            }
        }
        next_direction:;
    }
}
}
