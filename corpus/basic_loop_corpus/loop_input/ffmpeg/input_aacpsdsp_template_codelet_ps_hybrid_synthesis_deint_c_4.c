#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float INTFLOAT;

INTFLOAT out[2][38][64];
INTFLOAT (*in)[32][2];
int i;
int len;
int n;

void init_vars() {
    len = 38;
    i = 0;
    n = 0;

    in = malloc(sizeof(INTFLOAT[64][32][2]));
    if (!in) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (int idx0 = 0; idx0 < 64; idx0++) {
        for (int idx1 = 0; idx1 < 32; idx1++) {
            in[idx0][idx1][0] = (INTFLOAT)(idx0 * 32 * 2 + idx1 * 2 + 0);
            in[idx0][idx1][1] = (INTFLOAT)(idx0 * 32 * 2 + idx1 * 2 + 1);
        }
    }

    for (int idx0 = 0; idx0 < 2; idx0++) {
        for (int idx1 = 0; idx1 < 38; idx1++) {
            for (int idx2 = 0; idx2 < 64; idx2++) {
                out[idx0][idx1][idx2] = 0.0f;
            }
        }
    }
}