#include <stdio.h>

typedef struct {
    double real;
    double imag;
} dcomplex;

extern  double ex[221185];
extern dcomplex u0[128][256][256];
extern dcomplex u1[128][256][256];
extern int t;
extern int indexmap[128][256][256];
extern int d[3];
extern int i;
extern int j;
extern int k;



void loop(){
    // Variant 1: Change memory access pattern to strided access by iterating with a fixed stride
    // This variant accesses every 2nd element in each dimension to create a strided access pattern
    for (k = 0; k < d[2]; k += 2) {
        for (j = 0; j < d[1]; j += 2) {
            for (i = 0; i < d[0]; i += 2) {
                int idx = t * indexmap[k][j][i];
                u1[k][j][i].real = u0[k][j][i].real * ex[idx];
                u1[k][j][i].imag = u0[k][j][i].imag * ex[idx];
            }
        }
    }
    // Handle remaining elements to ensure full coverage (completing the iteration space)
    for (k = 1; k < d[2]; k += 2) {
        for (j = 0; j < d[1]; j++) {
            for (i = 0; i < d[0]; i++) {
                int idx = t * indexmap[k][j][i];
                u1[k][j][i].real = u0[k][j][i].real * ex[idx];
                u1[k][j][i].imag = u0[k][j][i].imag * ex[idx];
            }
        }
    }
    for (k = 0; k < d[2]; k++) {
        for (j = 1; j < d[1]; j += 2) {
            for (i = 0; i < d[0]; i++) {
                int idx = t * indexmap[k][j][i];
                u1[k][j][i].real = u0[k][j][i].real * ex[idx];
                u1[k][j][i].imag = u0[k][j][i].imag * ex[idx];
            }
        }
    }
    for (k = 0; k < d[2]; k++) {
        for (j = 0; j < d[1]; j++) {
            for (i = 1; i < d[0]; i += 2) {
                int idx = t * indexmap[k][j][i];
                u1[k][j][i].real = u0[k][j][i].real * ex[idx];
                u1[k][j][i].imag = u0[k][j][i].imag * ex[idx];
            }
        }
    }
}
