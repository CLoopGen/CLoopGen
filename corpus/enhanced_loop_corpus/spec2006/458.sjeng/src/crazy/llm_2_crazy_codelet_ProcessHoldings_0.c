#include <stdio.h>

#include <inttypes.h>

extern int holding[2][16];
extern int num_holding[2];
extern unsigned int zobrist[14][144];
extern unsigned int hold_hash;
extern char str[];
extern int c;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (c = 0; c <= 1; c++) {
        // Skip to next '[' using for-loop instead of while
        for (; str[i] != '[' && str[i] != 0; i++);
        if (str[i] == 0) return;
        i++; // consume '['

        // Process characters until ']'
        for (; str[i] != ']'; i++) {
            char ch = str[i];
            int piece_idx, hold_idx;

            // Map character to piece index with lookup logic
            if (ch == 'p' || ch == 'P') {
                piece_idx = (c == 0 ? 1 : 2);
            } else if (ch == 'q' || ch == 'Q') {
                piece_idx = (c == 0 ? 9 : 10);
            } else if (ch == 'r' || ch == 'R') {
                piece_idx = (c == 0 ? 7 : 8);
            } else if (ch == 'b' || ch == 'B') {
                piece_idx = (c == 0 ? 11 : 12);
            } else if (ch == 'n' || ch == 'N') {
                piece_idx = (c == 0 ? 3 : 4);
            } else {
                return;
            }

            // Update holding count and hash using direct indexing
            hold_idx = holding[c][piece_idx]++;
            num_holding[c]++;
            hold_hash ^= zobrist[piece_idx][hold_idx + 1];
        }
    }
}
