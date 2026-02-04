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
for (i = 0; i < N; i++) {
    float temp = 0.0f;
    int k = i;
    for (j = i; j < N; j++) {
        float atmp = Ap[((((((i) - 1) + 1) * (2 * (N) - ((i) - 1))) / 2) + (j) - (i))];
        temp += atmp * X[ix + (k - i) * incX];
        k++;
    }
    X[ix + (i - i) * incX] = (nonunit ? temp : temp * X[ix]);
    ix += incX;
}
}
