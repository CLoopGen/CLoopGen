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
    int local_numw = numw;
    int local_numb = numb;
    int found_break = 0;
    // Introduce local accumulators to remove WAW and WAR dependencies on shared counters
    for (i = 0; i < 4 && !found_break; i++) {
        a_sq = square + rook_o[i];
        b_sq = board[a_sq];
        if (b_sq == 5) {
            see_attackers[0][local_numw].piece = b_sq;
            see_attackers[0][local_numw].square = a_sq;
            local_numw++;
            found_break = 1;
        } else if (b_sq == 6) {
            see_attackers[1][local_numb].piece = b_sq;
            see_attackers[1][local_numb].square = a_sq;
            local_numb++;
            found_break = 1;
        } else if (b_sq != 0 && b_sq != 13) {
            if (b_sq == 7 || b_sq == 9) {
                see_attackers[0][local_numw].piece = b_sq;
                see_attackers[0][local_numw].square = a_sq;
                local_numw++;
                found_break = 1;
            } else if (b_sq == 8 || b_sq == 10) {
                see_attackers[1][local_numb].piece = b_sq;
                see_attackers[1][local_numb].square = a_sq;
                local_numb++;
                found_break = 1;
            }
        } else if (b_sq == 13) {
            // Simulate one-step ray continuation without while loop
            int next_sq = a_sq + rook_o[i];
            int next_b = board[next_sq];
            if (next_b == 5) {
                see_attackers[0][local_numw].piece = next_b;
                see_attackers[0][local_numw].square = next_sq;
                local_numw++;
                found_break = 1;
            } else if (next_b == 6) {
                see_attackers[1][local_numb].piece = next_b;
                see_attackers[1][local_numb].square = next_sq;
                local_numb++;
                found_break = 1;
            } else if (next_b == 7 || next_b == 9) {
                see_attackers[0][local_numw].piece = next_b;
                see_attackers[0][local_numw].square = next_sq;
                local_numw++;
                found_break = 1;
            } else if (next_b == 8 || next_b == 10) {
                see_attackers[1][local_numb].piece = next_b;
                see_attackers[1][local_numb].square = next_sq;
                local_numb++;
                found_break = 1;
            }
        }
    }
    // Commit accumulated results to global state after loop
    numw = local_numw;
    numb = local_numb;
}
