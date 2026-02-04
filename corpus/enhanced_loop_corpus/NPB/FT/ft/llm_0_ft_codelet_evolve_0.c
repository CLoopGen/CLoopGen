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
    for (j = 0; j < d[1]; j++) {
        for (i = 0; i < d[0]; i++) {
            u1[k][j][i].real = u0[k][j][i].real * ex[t * indexmap[k][j][i]];
            u1[k][j][i].imag = u0[k][j][i].imag * ex[t * indexmap[k][j][i]];
        }
    }
}
}
