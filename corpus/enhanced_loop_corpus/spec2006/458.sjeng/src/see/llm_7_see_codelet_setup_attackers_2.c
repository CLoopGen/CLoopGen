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
    int local_numw = numw;
    int local_numb = numb;
    int temp_a_sq;
    for (i = 0; i < 8; i++) {
        temp_a_sq = square + knight_o[i];
        int temp_b_sq = board[temp_a_sq];
        if (temp_b_sq == 3) {
            see_attackers[0][local_numw].piece = temp_b_sq;
            see_attackers[0][local_numw].square = temp_a_sq;
            local_numw++;
        } else if (temp_b_sq == 4) {
            see_attackers[1][local_numb].piece = temp_b_sq;
            see_attackers[1][local_numb].square = temp_a_sq;
            local_numb++;
        }
    }
    numw = local_numw;
    numb = local_numb;
}
