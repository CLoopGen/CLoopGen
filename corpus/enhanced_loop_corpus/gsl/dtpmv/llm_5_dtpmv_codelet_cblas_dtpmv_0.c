#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  double *Ap;
extern double *X;
extern  int incX;
extern int i;
extern int j;
extern  int nonunit;
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < N; i++) {
    if (i >= 0) {
        double atmp = Ap[(i * (2 * N - i + 1)) / 2]; // Simplified index: (((((i)-1)+1)*(2*(N)-((i)-1)))/2 + (i)-(i)) => (i*(2*N - i + 1))/2
        double temp = nonunit ? X[ix] * atmp : X[ix];
        int base_jx = (incX > 0) ? 0 : (N - 1) * (-incX);
        int jx = base_jx + (i + 1) * incX;
        for (j = i + 1; j < N; j++) {
            if (j != i) {
                atmp = Ap[(i * (2 * N - i + 1)) / 2 + (j - i)];
                temp += atmp * X[jx];
            }
            jx += incX;
        }
        X[ix] = temp;
        ix += incX;
    }
}
}
