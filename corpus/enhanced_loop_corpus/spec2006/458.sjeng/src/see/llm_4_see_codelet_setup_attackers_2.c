#include <stdio.h>

#include <inttypes.h>

typedef struct {
    int piece;
    int square;
} see_data;

extern int board[144];
extern see_data see_attackers[2][16];
extern int square;
extern  int knight_o[8];
extern int a_sq;
extern int b_sq;
extern int i;
extern int numw;
extern int numb;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i++) {
    a_sq = square + knight_o[i];
    b_sq = board[a_sq];
    if (b_sq != 3 && b_sq != 4) {
        continue;
    }
    if (b_sq == 3) {
        see_attackers[0][numw].piece = b_sq;
        see_attackers[0][numw].square = a_sq;
        numw++;
    } else {
        see_attackers[1][numb].piece = b_sq;
        see_attackers[1][numb].square = a_sq;
        numb++;
    }
}
}
