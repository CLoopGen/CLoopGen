#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    double real;
    double imag;
} complex;

typedef struct {
    complex e[3][3];
} su3_matrix;

su3_matrix *a;
su3_matrix *b;
su3_matrix *c;
int i;
int j;

void init_vars() {
    const size_t data_size = 1 << 20; // ~8MB per matrix (each su3_matrix is 144 bytes)
    const int num_matrices = data_size / sizeof(su3_matrix);
    
    a = (su3_matrix*)aligned_alloc(64, num_matrices * sizeof(su3_matrix));
    b = (su3_matrix*)aligned_alloc(64, num_matrices * sizeof(su3_matrix));
    c = (su3_matrix*)aligned_alloc(64, num_matrices * sizeof(su3_matrix));

    uint64_t seed = time(NULL);
    for (int idx = 0; idx < num_matrices; idx++) {
        for (int m = 0; m < 3; m++) {
            for (int n = 0; n < 3; n++) {
                a[idx].e[m][n].real = (double)(seed = (seed * 0x5DEECE66DLL + 0xBLL) & 0xFFFFFFFFFFFFLL) / 0x100000000LL;
                a[idx].e[m][n].imag = (double)(seed = (seed * 0x5DEECE66DLL + 0xBLL) & 0xFFFFFFFFFFFFLL) / 0x100000000LL;
                b[idx].e[m][n].real = (double)(seed = (seed * 0x5DEECE66DLL + 0xBLL) & 0xFFFFFFFFFFFFLL) / 0x100000000LL;
                b[idx].e[m][n].imag = (double)(seed = (seed * 0x5DEECE66DLL + 0xBLL) & 0xFFFFFFFFFFFFLL) / 0x100000000LL;
                c[idx].e[m][n].real = 0.0;
                c[idx].e[m][n].imag = 0.0;
            }
        }
    }

    i = 0;
    j = 0;
}