#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double jas_cmreal_t;

int i;
jas_cmreal_t mat[3][4];

void init_vars() {
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 4; ++col) {
            mat[row][col] = 0.0;
        }
    }
    i = 0;
}