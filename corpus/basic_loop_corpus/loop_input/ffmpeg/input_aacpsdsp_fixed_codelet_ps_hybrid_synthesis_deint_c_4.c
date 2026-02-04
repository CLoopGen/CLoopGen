#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int INTFLOAT;

INTFLOAT out[2][38][64];
INTFLOAT (*in)[32][2];
int i;
int len;
int n;

void init_vars() {
    len = 38;
    i = 0;

    in = (INTFLOAT(*)[32][2])calloc(64 * 32 * 2, sizeof(INTFLOAT));
    if (!in) {
        exit(1);
    }

    for (int idx = 0; idx < 64; idx++) {
        for (int j = 0; j < 32; j++) {
            in[idx][j][0] = (INTFLOAT)(idx + j);
            in[idx][j][1] = (INTFLOAT)(idx - j);
        }
    }

    for (int a = 0; a < 2; a++) {
        for (int b = 0; b < 38; b++) {
            for (int c = 0; c < 64; c++) {
                out[a][b][c] = 0;
            }
        }
    }
}