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

        // Process each character inside the bracket until ']'
        for (; str[i] != ']'; i++) {
            int piece_type, index;
            char ch = str[i];
            if (ch == 'p' || ch == 'P') {
                piece_type = (c == 0 ? 1 : 2);
            } else if (ch == 'q' || ch == 'Q') {
                piece_type = (c == 0 ? 9 : 10);
            } else if (ch == 'r' || ch == 'R') {
                piece_type = (c == 0 ? 7 : 8);
            } else if (ch == 'b' || ch == 'B') {
                piece_type = (c == 0 ? 11 : 12);
            } else if (ch == 'n' || ch == 'N') {
                piece_type = (c == 0 ? 3 : 4);
            } else {
                return;
            }

            // Update holding count and hash with eliminated redundant lookups
            index = piece_type;
            holding[c][index]++;
            num_holding[c]++;
            hold_hash ^= zobrist[piece_type][holding[c][index]];
        }
    }
}
