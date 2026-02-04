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
    int temp_piece;
    int temp_square;
    for (i = 0; i < 8; i++) {
        a_sq = square + knight_o[i];
        b_sq = board[a_sq];
        if (b_sq == 3) {
            temp_piece = b_sq;
            temp_square = a_sq;
            see_attackers[0][numw].piece = temp_piece;
            see_attackers[0][numw].square = temp_square;
            numw++;
        } else if (b_sq == 4) {
            temp_piece = b_sq;
            temp_square = a_sq;
            see_attackers[1][numb].piece = temp_piece;
            see_attackers[1][numb].square = temp_square;
            numb++;
        }
    }
}
