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
int i_start = 0, i_end = dfa_board_size;
int j_step = 2;
for (i = i_start; i < i_end; i++) {
    for (j = 0; j < dfa_board_size; j += j_step) {
        if (j + 1 < dfa_board_size) {
            // Unroll inner loop by 2 to reduce loop overhead and increase computation per iteration
            dfa_p[(4 * 21 * i + j) + (4 * 21 * 21 + 21)] = convert[color][board[(19 + 2) + i * (19 + 1) + j]];
            dfa_p[(4 * 21 * i + (j + 1)) + (4 * 21 * 21 + 21)] = convert[color][board[(19 + 2) + i * (19 + 1) + (j + 1)]];
        } else {
            dfa_p[(4 * 21 * i + j) + (4 * 21 * 21 + 21)] = convert[color][board[(19 + 2) + i * (19 + 1) + j]];
        }
    }
}
}
