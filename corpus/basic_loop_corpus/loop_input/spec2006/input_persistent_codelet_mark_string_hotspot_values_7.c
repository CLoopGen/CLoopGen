#include <stdio.h>
#include <inttypes.h>

typedef unsigned char Intersection;

Intersection board[421];
float values[400];
int m;
int n;
float contribution;
int i;
int j;

void init_vars() {
    for (int idx = 0; idx < 421; idx++) {
        board[idx] = (idx < 400) ? 0 : 1;
    }
    for (int idx = 0; idx < 400; idx++) {
        values[idx] = 1.0f;
    }
    m = 10;
    n = 10;
    contribution = 0.5f;
}