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
    // Variant 1: Strided Memory Access with Unrolled Conditions
    for (i = 0; i < 4; i++) {
        a_sq = square + bishop_o[i];
        b_sq = board[a_sq];
        
        // Use strided access pattern by precomputing next potential index
        int next_a_sq = a_sq + bishop_o[i];
        
        if (b_sq == 1 && (i & 1)) {
            see_attackers[0][numw].piece = b_sq;
            see_attackers[0][numw].square = a_sq;
            numw++;
            continue;
        } else if (b_sq == 2 && !(i & 1)) {
            see_attackers[1][numb].piece = b_sq;
            see_attackers[1][numb].square = a_sq;
            numb++;
            continue;
        } else if (b_sq == 5) {
            see_attackers[0][numw].piece = b_sq;
            see_attackers[0][numw].square = a_sq;
            numw++;
            continue;
        } else if (b_sq == 6) {
            see_attackers[1][numb].piece = b_sq;
            see_attackers[1][numb].square = a_sq;
            numb++;
            continue;
        } else if (b_sq != 0) {
            // Simulate one-step ray tracing without while: unroll first step
            b_sq = board[next_a_sq];
            a_sq = next_a_sq;
            
            if (b_sq == 11 || b_sq == 9) {
                see_attackers[0][numw].piece = b_sq;
                see_attackers[0][numw].square = a_sq;
                numw++;
            } else if (b_sq == 12 || b_sq == 10) {
                see_attackers[1][numb].piece = b_sq;
                see_attackers[1][numb].square = a_sq;
                numb++;
            }
            // No further traversal; break condition implied
        }
    }
}
