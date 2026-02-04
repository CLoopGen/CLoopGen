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
for (i = 0; i < N; i += 2) {
    float temp0 = X[ix];
    float temp1 = (i + 1 < N) ? X[ix + incX] : 0.0f;
    float atmp0 = Ap[(((i) * ((i) + 1)) / 2 + (i))];
    float atmp1 = (i + 1 < N) ? Ap[(((i+1) * ((i+2)) / 2) + (i+1))] : 0.0f;
    
    if (nonunit) {
        temp0 *= atmp0;
        if (i + 1 < N) temp1 *= atmp1;
    }

    int jx0 = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX))) + (i + 1) * incX;
    int jx1 = jx0 + incX;

    for (j = i + 1; j < N; j++) {
        atmp0 = Ap[(((j) * ((j) + 1)) / 2 + (i))];
        temp0 += atmp0 * X[jx0];
        
        if (i + 1 < N && j > i + 1) {
            atmp1 = Ap[(((j) * ((j) + 1)) / 2 + (i+1))];
            temp1 += atmp1 * X[jx1];
        }
        jx0 += incX;
        jx1 += incX;
    }

    X[ix] = temp0;
    if (i + 1 < N) {
        X[ix + incX] = temp1;
    }
    ix += 2 * incX;
}
}
