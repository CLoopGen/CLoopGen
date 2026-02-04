#include <stdio.h>
#include <inttypes.h>

typedef unsigned char Intersection;

int delta[8] = {1, -1, 19, -19, 2, -2, 3, -3};

Intersection board[421];
int k;
int dpos;
char mn[400];

void init_vars() {
    for (int i = 0; i < 421; i++) {
        board[i] = (i % 7 == 0) ? 3 : (i % 3);
    }
    for (int i = 0; i < 400; i++) {
        mn[i] = (i % 100 == 0) ? 1 : 0;
    }
}