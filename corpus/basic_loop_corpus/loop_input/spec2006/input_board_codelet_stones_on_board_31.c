#include <inttypes.h>

typedef unsigned char Intersection;

Intersection board[421];
int white_stones;
int black_stones;
int pos;

void init_vars() {
    white_stones = 0;
    black_stones = 0;
    for (int i = 0; i < 421; i++) {
        board[i] = (i % 7) + 1;
    }
}