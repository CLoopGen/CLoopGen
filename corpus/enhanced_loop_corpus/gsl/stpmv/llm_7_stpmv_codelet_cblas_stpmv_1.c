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
    float *restrict local_X = X;
    int *restrict local_ix = &ix;
    int local_N = N;
    float *restrict local_Ap = Ap;
    int local_incX = incX;
    int local_nonunit = nonunit;

    for (i = local_N; i > 0 && i--;) {
        int base_idx = (i * (i + 1)) / 2;
        float atmp_diag = local_Ap[base_idx + i];
        float temp = local_nonunit ? local_X[*local_ix] * atmp_diag : local_X[*local_ix];
        int jx = (local_incX > 0 ? 0 : (local_N - 1) * (-local_incX));
        
        for (j = 0; j < i; j++) {
            float a_val = local_Ap[base_idx + j];
            temp += a_val * local_X[jx];
            jx += local_incX;
        }

        local_X[*local_ix] = temp;
        *local_ix -= local_incX;
    }
}
