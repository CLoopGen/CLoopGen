#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  float alpha;
extern  float *X;
extern  int incX;
extern float *Ap;
extern int i;
extern int j;
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
float running_factor = 1.0f;
for (i = 0; i < N; i++) {
    running_factor *= alpha;
    const float tmp = running_factor * X[ix];
    int jx = ix;
    for (j = i; j < N; j++) {
        int index = (((i * (2 * N - i + 1)) / 2) + (j - i));
        Ap[index] = Ap[index] + X[jx] * tmp;
        jx += incX;
    }
    ix += incX;
}
}
