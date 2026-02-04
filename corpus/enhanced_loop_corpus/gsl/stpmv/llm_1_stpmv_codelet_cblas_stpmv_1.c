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
        if (i > 0) {
            j = 0;
            atmp = Ap[(((i) * ((i) + 1)) / 2 + (j))];
            temp += atmp * X[jx];
            jx += incX;
            for (j = 1; j < i; j++) {
                atmp = Ap[(((i) * ((i) + 1)) / 2 + (j))];
                temp += atmp * X[jx];
                jx += incX;
            }
        }
        X[ix] = temp;
        ix -= incX;
    }
}
