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
    for (int c = 0; c <= 1; c++) {
        for (int found_bracket = 0; i < 1000 && !found_bracket; ) {
            if (str[i++] == '[') {
                found_bracket = 1;
            }
            if (str[i] == 0) return;
        }
        for (; str[i] != ']'; ) {
            char ch = str[i++];
            int piece_idx, hold_idx;
            switch (ch) {
                case 'p': case 'P':
                    piece_idx = (c == 0 ? 1 : 2);
                    holding[c][piece_idx]++;
                    num_holding[c]++;
                    hold_hash ^= zobrist[piece_idx][holding[c][piece_idx]];
                    break;
                case 'q': case 'Q':
                    piece_idx = (c == 0 ? 9 : 10);
                    holding[c][piece_idx]++;
                    num_holding[c]++;
                    hold_hash ^= zobrist[piece_idx][holding[c][piece_idx]];
                    break;
                case 'r': case 'R':
                    piece_idx = (c == 0 ? 7 : 8);
                    holding[c][piece_idx]++;
                    num_holding[c]++;
                    hold_hash ^= zobrist[piece_idx][holding[c][piece_idx]];
                    break;
                case 'b': case 'B':
                    piece_idx = (c == 0 ? 11 : 12);
                    holding[c][piece_idx]++;
                    num_holding[c]++;
                    hold_hash ^= zobrist[piece_idx][holding[c][piece_idx]];
                    break;
                case 'n': case 'N':
                    piece_idx = (c == 0 ? 3 : 4);
                    holding[c][piece_idx]++;
                    num_holding[c]++;
                    hold_hash ^= zobrist[piece_idx][holding[c][piece_idx]];
                    break;
                default:
                    return;
            }
        }
    }
}
