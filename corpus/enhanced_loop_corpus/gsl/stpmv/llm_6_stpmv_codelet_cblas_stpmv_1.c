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
        float sum = 0.0f;
        for (j = 0; j < i; j++) {
            float a_val = Ap[(((i) * ((i) + 1)) / 2 + (j))];
            sum += a_val * X[jx];
            jx += incX;
        }
        temp += sum;
        X[ix] = temp;
        ix -= incX;
    }
}
