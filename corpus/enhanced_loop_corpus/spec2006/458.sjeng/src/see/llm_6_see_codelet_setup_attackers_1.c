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
    int temp_a_sq[4];
    int temp_b_sq[4];
    for (i = 0; i < 4; i++) {
        temp_a_sq[i] = square + bishop_o[i];
        temp_b_sq[i] = board[temp_a_sq[i]];
    }
    for (i = 0; i < 4; i++) {
        a_sq = temp_a_sq[i];
        b_sq = temp_b_sq[i];
        if (b_sq == 1 && i % 2) {
            see_attackers[0][numw].piece = b_sq;
            see_attackers[0][numw].square = a_sq;
            numw++;
            break;
        } else if (b_sq == 2 && !(i % 2)) {
            see_attackers[1][numb].piece = b_sq;
            see_attackers[1][numb].square = a_sq;
            numb++;
            break;
        } else if (b_sq == 5) {
            see_attackers[0][numw].piece = b_sq;
            see_attackers[0][numw].square = a_sq;
            numw++;
            break;
        } else if (b_sq == 6) {
            see_attackers[1][numb].piece = b_sq;
            see_attackers[1][numb].square = a_sq;
            numb++;
            break;
        } else {
            int next_a_sq = a_sq;
            int next_b_sq = b_sq;
            for (int j = 0; j < 1; j++) {
                if (next_b_sq == 13) {
                    next_a_sq += bishop_o[i];
                    next_b_sq = board[next_a_sq];
                    j--; // simulate continuation of traversal along ray
                }
            }
            if (next_b_sq == 11 || next_b_sq == 9) {
                see_attackers[0][numw].piece = next_b_sq;
                see_attackers[0][numw].square = next_a_sq;
                numw++;
                break;
            } else if (next_b_sq == 12 || next_b_sq == 10) {
                see_attackers[1][numb].piece = next_b_sq;
                see_attackers[1][numb].square = next_a_sq;
                numb++;
                break;
            }
        }
    }
}
