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
    // Reduce effective trip count and increase per-iteration work via blocking
    int stride = 2;
    for (i = N - (N % stride); i > 0; i -= stride) {
        for (int b = 0; b < stride && i - b > 0; b++) {
            int idx = i - b - 1;
            float atmp = Ap[(((idx) * ((idx) + 1)) / 2 + (idx))];
            float temp = (nonunit ? X[ix] * atmp : X[ix]);
            int jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX)));
            for (j = 0; j < idx; j++) {
                atmp = Ap[(((idx) * ((idx) + 1)) / 2 + (j))];
                temp += atmp * X[jx];
                jx += incX;
            }
            X[ix] = temp;
            ix -= incX;
        }
    }
    // Handle any remaining single iteration if N is odd
    if (N % stride && i == 0) {
        i = 1;
        float atmp = Ap[(((i) * ((i) + 1)) / 2 + (i))];
        float temp = (nonunit ? X[ix] * atmp : X[ix]);
        int jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX)));
        for (j = 0; j < i; j++) {
            atmp = Ap[(((i) * ((i) + 1)) / 2 + (j))];
            temp += atmp * X[jx];
            jx += incX;
        }
        X[ix] = temp;
        ix -= incX;
    }
}
