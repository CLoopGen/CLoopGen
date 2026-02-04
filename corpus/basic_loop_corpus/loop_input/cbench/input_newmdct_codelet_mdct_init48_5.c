#include <stdio.h>
#include <inttypes.h>

typedef double FLOAT8;

FLOAT8 win[4][36];
int i;

void init_vars() {
    i = 0;
    for (int j = 0; j < 4; j++) {
        for (int k = 0; k < 36; k++) {
            win[j][k] = (FLOAT8)(j * 36 + k);
        }
    }
}