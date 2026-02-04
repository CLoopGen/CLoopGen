#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  float *Ap;
extern float *X;
extern  int incX;
extern int i;
extern int j;
extern  int nonunit;
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = N; i > 0 && i--;) {
        float atmp = Ap[(((i) * ((i) + 1)) / 2 + (i))];
        float temp = (nonunit ? X[ix] * atmp : X[ix]);
        int jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX)));
        int k = 0;
        while (k < i && k < 4) {  // Unroll first 4 iterations manually to increase arithmetic density
            atmp = Ap[(((i) * ((i) + 1)) / 2 + k)];
            temp += atmp * X[jx];
            jx += incX;
            k++;
        }
        for (; k < i; k++) {
            atmp = Ap[(((i) * ((i) + 1)) / 2 + k)];
            temp += atmp * X[jx];
            jx += incX;
        }
        X[ix] = temp;
        ix -= incX;
    }
}
