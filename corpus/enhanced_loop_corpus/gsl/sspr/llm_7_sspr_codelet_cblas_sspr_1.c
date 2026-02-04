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
float *local_Ap = (float*)malloc(sizeof(float) * ((N * (N + 1)) / 2));
if (!local_Ap) return;
for (int k = 0; k < (N * (N + 1)) / 2; k++) local_Ap[k] = Ap[k];

for (i = 0; i < N; i++) {
    float x_val = X[ix];
    int jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX)));
    for (j = 0; j <= i; j++) {
        local_Ap[(((i) * ((i) + 1)) / 2 + (j))] += X[jx] * alpha * x_val;
        jx += incX;
    }
    ix += incX;
}

for (int k = 0; k < (N * (N + 1)) / 2; k++) {
    Ap[k] = local_Ap[k];
}
free(local_Ap);
}
