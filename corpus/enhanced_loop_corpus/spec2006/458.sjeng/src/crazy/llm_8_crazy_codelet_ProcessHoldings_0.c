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
        // Skip to next '[' character or return if end of string
        for (; str[i] != '[' && str[i] != 0; i++);
        if (str[i] == 0) return;
        i++; // Move past '['

        // Process until ']'
        for (; str[i] != ']'; i++) {
            char ch = str[i];
            int piece_index, hold_index;

            // Map character to piece type and determine index based on color (c)
            if (ch == 'p' || ch == 'P') {
                piece_index = (c == 0 ? 1 : 2);
            } else if (ch == 'q' || ch == 'Q') {
                piece_index = (c == 0 ? 9 : 10);
            } else if (ch == 'r' || ch == 'R') {
                piece_index = (c == 0 ? 7 : 8);
            } else if (ch == 'b' || ch == 'B') {
                piece_index = (c == 0 ? 11 : 12);
            } else if (ch == 'n' || ch == 'N') {
                piece_index = (c == 0 ? 3 : 4);
            } else {
                return;
            }

            hold_index = piece_index;
            holding[c][hold_index]++;
            num_holding[c]++;
            hold_hash ^= zobrist[piece_index][holding[c][hold_index]];
        }
    }
}
