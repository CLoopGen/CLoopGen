#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float INTFLOAT;

#define LEN 256

INTFLOAT (*out)[32][2];
INTFLOAT L[2][38][64];
int i;
int len = 32;
int j;

void init_vars() {
    i = 0;
    j = 0;
    len = 32;

    out = (INTFLOAT(*)[32][2])calloc(64 * 32 * 2, sizeof(INTFLOAT));
    if (!out) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int k = 0; k < 2; k++) {
        for (int m = 0; m < 38; m++) {
            for (int n = 0; n < 64; n++) {
                L[k][m][n] = (INTFLOAT)(k * 1000000 + m * 1000 + n);
            }
        }
    }
}