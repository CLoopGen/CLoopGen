#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern int dfa_board_size;
extern int dfa_p[7056];
extern const int convert[3][4];
extern int color;
extern int i;
extern int j;
extern Intersection board[421];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < dfa_board_size; i++) {
    for (j = 0; j < dfa_board_size; j++) {
        if (i % 2 == 0) {
            dfa_p[(4 * 21 * (i) + (j)) + (4 * 21 * (21) + (21))] = convert[color][board[((19 + 2) + (i) * (19 + 1) + (j))]];
        } else {
            continue;
        }
    }
}
}
