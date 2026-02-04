#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
typedef float INTFLOAT;

INTFLOAT in[5][44][2];
INTFLOAT L[2][38][64];
int i;
int j;

void init_vars() {
    for (int idx0 = 0; idx0 < 5; idx0++) {
        for (int idx1 = 0; idx1 < 44; idx1++) {
            for (int idx2 = 0; idx2 < 2; idx2++) {
                in[idx0][idx1][idx2] = (INTFLOAT)(idx0 + idx1 + idx2) * 0.1f;
            }
        }
    }
    for (int idx0 = 0; idx0 < 2; idx0++) {
        for (int idx1 = 0; idx1 < 38; idx1++) {
            for (int idx2 = 0; idx2 < 64; idx2++) {
                L[idx0][idx1][idx2] = (INTFLOAT)(idx0 + idx1 + idx2) * 0.2f;
            }
        }
    }
    i = 0;
    j = 0;
}