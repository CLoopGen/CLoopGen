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
    // Strided memory access via precomputed index array to simulate indirect access pattern
    int offsets[4] = {rook_o[0], rook_o[1], rook_o[2], rook_o[3]};
    for (i = 0; i < 4; i++) {
        int step = offsets[i];
        a_sq = square + step;
        b_sq = board[a_sq];
        if (b_sq == 5) {
            see_attackers[0][numw].piece = b_sq;
            see_attackers[0][numw].square = a_sq;
            numw++;
            continue;
        } else if (b_sq == 6) {
            see_attackers[1][numb].piece = b_sq;
            see_attackers[1][numb].square = a_sq;
            numb++;
            continue;
        } else if (b_sq == 0) {
            continue;
        }

        // Simulate linear traversal along direction without while
        for (int depth = 1; depth <= 8; depth++) { // Max possible depth on a 12x12 board
            a_sq += step;
            b_sq = board[a_sq];
            if (b_sq == 7 || b_sq == 9) {
                see_attackers[0][numw].piece = b_sq;
                see_attackers[0][numw].square = a_sq;
                numw++;
                break;
            } else if (b_sq == 8 || b_sq == 10) {
                see_attackers[1][numb].piece = b_sq;
                see_attackers[1][numb].square = a_sq;
                numb++;
                break;
            } else if (b_sq != 13) {
                break;
            }
        }
    }
}
