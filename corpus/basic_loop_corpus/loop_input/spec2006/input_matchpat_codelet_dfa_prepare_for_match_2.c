#include <stdio.h>
#include <inttypes.h>

typedef unsigned char Intersection;

int dfa_board_size = 21;
int dfa_p[7056];
const int convert[3][4] = {
    {0, 1, 2, 3},
    {4, 5, 6, 7},
    {8, 9, 10, 11}
};
int color = 1;
int i;
int j;
Intersection board[421];

void init_vars() {
    for (int idx = 0; idx < 7056; idx++) {
        dfa_p[idx] = 0;
    }
    for (int idx = 0; idx < 421; idx++) {
        board[idx] = (unsigned char)(idx % 3);
    }
    dfa_board_size = 21;
    color = 1;
}