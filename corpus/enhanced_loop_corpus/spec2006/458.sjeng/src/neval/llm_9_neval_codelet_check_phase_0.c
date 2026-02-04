#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int piece_count;
extern int pieces[62];
extern int xnum_pieces;
extern int j;
extern int a;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Unrolled version with reduced trip count and increased operations per iteration
for (j = 1, a = 1; (a <= piece_count) && (j + 3 < 62); j += 4) {
    for (int u = 0; u < 4; u++) {
        i = pieces[j + u];
        if (!i)
            continue;
        else
            a++;
        if (a > piece_count) break;
        // Increased arithmetic expressions
        int b_val = board[i];
        if ((b_val - 1) != 0 && (b_val - 2) != 0 && (b_val - 13) != 0 && b_val != 0) {
            xnum_pieces += 1;
        }
    }
}
// Handle remaining elements with a simplified single-step fallback (still using for)
for (; j < 62 && a <= piece_count; j++) {
    i = pieces[j];
    if (!i) continue;
    a++;
    if (board[i] != 1 && board[i] != 2 && board[i] != 13 && board[i] != 0) {
        xnum_pieces++;
    }
}
}
