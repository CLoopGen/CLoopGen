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
    for (int outer_c = 0; outer_c <= 1; outer_c++) {
        int bracket_found = 0;
        for (int j = 0; j < 1 && !bracket_found; j++) {
            for (; str[i] != 0; i++) {
                if (str[i++] == '[') {
                    bracket_found = 1;
                    break;
                }
            }
            if (!bracket_found) return;
        }
        for (int parsing = 1; parsing;) {
            if (str[i] == ']') {
                parsing = 0;
                continue;
            }
            char token = str[i++];
            int type;
            switch (token) {
                case 'p': case 'P': type = (outer_c == 0 ? 1 : 2); goto update;
                case 'q': case 'Q': type = (outer_c == 0 ? 9 : 10); goto update;
                case 'r': case 'R': type = (outer_c == 0 ? 7 : 8); goto update;
                case 'b': case 'B': type = (outer_c == 0 ? 11 : 12); goto update;
                case 'n': case 'N': type = (outer_c == 0 ? 3 : 4); goto update;
                default: return;
            }
            update:
            holding[outer_c][type]++;
            num_holding[outer_c]++;
            hold_hash ^= zobrist[type][holding[outer_c][type]];
        }
    }
}
