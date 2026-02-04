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
    // Variant 2: Indirect Memory Access via Index Remapping
    int index_map[4] = {0, 2, 1, 3}; // Shuffle access order to create indirect pattern
    
    for (i = 0; i < 4; i++) {
        int idx = index_map[i]; // Indirect indexing
        a_sq = square + bishop_o[idx];
        b_sq = board[a_sq];
        
        // Precompute two steps along the ray for speculative access
        int step1 = a_sq + bishop_o[idx];
        int step2 = step1 + bishop_o[idx];
        
        if (b_sq == 1 && (idx % 2)) {
            see_attackers[0][numw].piece = b_sq;
            see_attackers[0][numw].square = a_sq;
            numw++;
            continue;
        } else if (b_sq == 2 && !(idx % 2)) {
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
            // First indirect continuation check
            b_sq = board[step1];
            a_sq = step1;
            
            if (b_sq == 11 || b_sq == 9) {
                see_attackers[0][numw].piece = b_sq;
                see_attackers[0][numw].square = a_sq;
                numw++;
            } else if (b_sq == 12 || b_sq == 10) {
                see_attackers[1][numb].piece = b_sq;
                see_attackers[1][numb].square = a_sq;
                numb++;
            } else if (b_sq == 13) {
                // Second hop if still empty (simulates continued ray)
                b_sq = board[step2];
                a_sq = step2;
                
                if (b_sq == 11 || b_sq == 9) {
                    see_attackers[0][numw].piece = b_sq;
                    see_attackers[0][numw].square = a_sq;
                    numw++;
                } else if (b_sq == 12 || b_sq == 10) {
                    see_attackers[1][numb].piece = b_sq;
                    see_attackers[1][numb].square = a_sq;
                    numb++;
                }
            }
        }
    }
}
