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
for (i = 0; i < 4; i++) {
    a_sq = square + bishop_o[i];
    b_sq = board[a_sq];
    if (b_sq == 1 && i % 2) {
        see_attackers[0][numw].piece = b_sq;
        see_attackers[0][numw].square = a_sq;
        numw++;
    } else if (b_sq == 2 && !(i % 2)) {
        see_attackers[1][numb].piece = b_sq;
        see_attackers[1][numb].square = a_sq;
        numb++;
    } else if (b_sq == 5) {
        see_attackers[0][numw].piece = b_sq;
        see_attackers[0][numw].square = a_sq;
        numw++;
    } else if (b_sq == 6) {
        see_attackers[1][numb].piece = b_sq;
        see_attackers[1][numb].square = a_sq;
        numb++;
    } else {
        for (int j = 0; j < 10 && b_sq != 0; j++) {
            if (b_sq == 11 || b_sq == 9) {
                see_attackers[0][numw].piece = b_sq;
                see_attackers[0][numw].square = a_sq;
                numw++;
                break;
            } else if (b_sq == 12 || b_sq == 10) {
                see_attackers[1][numb].piece = b_sq;
                see_attackers[1][numb].square = a_sq;
                numb++;
                break;
            } else if (b_sq != 13)
                break;
            a_sq += bishop_o[i];
            b_sq = board[a_sq];
        }
    }
}
}
