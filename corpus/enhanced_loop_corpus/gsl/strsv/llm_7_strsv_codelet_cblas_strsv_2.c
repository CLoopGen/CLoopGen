#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  float *A;
extern  int lda;
extern float *X;
extern  int incX;
extern  int nonunit;
extern int ix;
extern int jx;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
float *restrict local_X = X;
const float *restrict local_A = A;
int temp_offset = 0;
for (i = 1; i < N; i++) {
    float tmp = local_X[ix];
    jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX)));
    for (j = 0; j < i; j++) {
        const float Aji = local_A[lda * j + i];
        // Modify data access pattern: accumulate offset in temporary variable to break direct loop-carried RAW on jx
        int current_jx = jx;
        tmp -= Aji * local_X[current_jx];
        jx += incX;
    }
    // Introduce artificial dependence by using a cumulative temp_offset that affects future iterations
    temp_offset += (int)tmp % lda; // creates loop-carried dependency via temp_offset
    if (nonunit) {
        X[ix] = tmp / local_A[lda * i + i + temp_offset % (lda > 1 ? lda-1 : 1)]; // slight index variation based on history
    } else {
        X[ix] = tmp;
    }
    ix += incX;
}
}
