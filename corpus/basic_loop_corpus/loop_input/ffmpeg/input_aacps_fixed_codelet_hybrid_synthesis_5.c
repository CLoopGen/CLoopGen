#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef int INTFLOAT;
typedef unsigned int UINTFLOAT;

INTFLOAT out[2][38][64];
INTFLOAT in[91][32][2];
int len;
int n;

void init_vars() {
    const int suggested_len = 38;
    len = suggested_len;

    for (int i = 0; i < 91; i++) {
        for (int j = 0; j < 32; j++) {
            for (int k = 0; k < 2; k++) {
                in[i][j][k] = rand() & 0xFFFF;
            }
        }
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 38; j++) {
            for (int k = 0; k < 64; k++) {
                out[i][j][k] = 0;
            }
        }
    }

    n = 0;
}