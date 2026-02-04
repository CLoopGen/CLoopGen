#include <stdio.h>
#include <inttypes.h>

typedef double FLOAT8;

FLOAT8 win[4][36];
int k;

void init_vars() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 36; j++) {
            win[i][j] = (FLOAT8)(i * 36 + j);
        }
    }
    k = 0;
}