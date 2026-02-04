#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float INTFLOAT;
typedef float UINTFLOAT;

#define LEN 128

INTFLOAT out[2][38][64] = {0};
INTFLOAT in[91][32][2] = {0};
int len = LEN;
int n = 0;

void init_vars() {
    for (int i = 0; i < 91; i++) {
        for (int j = 0; j < 32; j++) {
            for (int k = 0; k < 2; k++) {
                in[i][j][k] = (INTFLOAT)(i + j + k);
            }
        }
    }
    len = 32;
}