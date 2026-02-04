#include <stdio.h>
#include <inttypes.h>

typedef unsigned char Intersection;

Intersection board[421];
char goal[400];
char active[400];
int pos;

void init_vars() {
    for (int i = 0; i < 421; i++) {
        board[i] = (i >= 400 || i < 21) ? 3 : (i % 7);
    }
    for (int i = 0; i < 400; i++) {
        goal[i] = (i % 3) ? 1 : 0;
        active[i] = 0;
    }
    pos = 0;
}