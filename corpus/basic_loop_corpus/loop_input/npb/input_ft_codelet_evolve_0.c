#include <stdio.h>

typedef struct {
    double real;
    double imag;
} dcomplex;

double ex[221185];
dcomplex u0[128][256][256];
dcomplex u1[128][256][256];
int t;
int indexmap[128][256][256];
int d[3];
int i;
int j;
int k;

void init_vars() {
    d[0] = 256;
    d[1] = 256;
    d[2] = 128;
    t = 1;

    for (int k = 0; k < 128; k++) {
        for (int j = 0; j < 256; j++) {
            for (int i = 0; i < 256; i++) {
                u0[k][j][i].real = 1.0;
                u0[k][j][i].imag = 0.5;
                indexmap[k][j][i] = (k * 256 * 256 + j * 256 + i) % 221185;
            }
        }
    }

    for (int idx = 0; idx < 221185; idx++) {
        ex[idx] = 1.0 + idx * 0.00001;
    }
}