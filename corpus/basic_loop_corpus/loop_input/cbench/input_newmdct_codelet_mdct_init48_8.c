#include <stdio.h>
#include <inttypes.h>

typedef double FLOAT8;

FLOAT8 win[4][36];
int i;
FLOAT8 max;

void init_vars() {
    max = 1000.0;
    for (int j = 0; j < 4; j++) {
        for (int k = 0; k < 36; k++) {
            win[j][k] = (j + 1) * (k + 1);
        }
    }
}