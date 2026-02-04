#include <stdio.h>

typedef struct {
    double real;
    double imag;
} dcomplex;

int fftblock = 18;
int n = 256;
dcomplex x[256][18];
dcomplex y[256][18];
int i;
int j;

void init_vars() {
    for (int idx_j = 0; idx_j < n; idx_j++) {
        for (int idx_i = 0; idx_i < fftblock; idx_i++) {
            y[idx_j][idx_i].real = (double)(idx_i + idx_j);
            y[idx_j][idx_i].imag = (double)(idx_i - idx_j);
            x[idx_j][idx_i].real = 0.0;
            x[idx_j][idx_i].imag = 0.0;
        }
    }
}