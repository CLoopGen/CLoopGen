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
    for (k = 0; k < d[2]; k++) {
        for (j = 0; j < d[1]; j += 2) {
            for (i = 0; i < d[0]; i++) {
                int idx = t * indexmap[k][j][i];
                if (idx < 221185 && idx >= 0) {
                    u1[k][j][i].real = u0[k][j][i].real * ex[idx];
                    u1[k][j][i].imag = u0[k][j][i].imag * ex[idx];
                }
                if (j + 1 < d[2]) {
                    int idx2 = t * indexmap[k][j+1][i];
                    if (idx2 < 221185 && idx2 >= 0) {
                        u1[k][j+1][i].real = u0[k][j+1][i].real * ex[idx2];
                        u1[k][j+1][i].imag = u0[k][j+1][i].imag * ex[idx2];
                    }
                }
            }
        }
    }
}
