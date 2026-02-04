#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int INTFLOAT;

INTFLOAT in[5][44][2];
INTFLOAT L[2][38][64];
int i;
int j;

void init_vars() {
    for (int i0 = 0; i0 < 5; i0++) {
        for (int i1 = 0; i1 < 44; i1++) {
            for (int i2 = 0; i2 < 2; i2++) {
                in[i0][i1][i2] = rand() % 1000;
            }
        }
    }
    for (int i0 = 0; i0 < 2; i0++) {
        for (int i1 = 0; i1 < 38; i1++) {
            for (int i2 = 0; i2 < 64; i2++) {
                L[i0][i1][i2] = rand() % 1000;
            }
        }
    }
}