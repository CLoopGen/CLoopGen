#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  int K;
extern  double *A;
extern  int lda;
extern double *X;
extern  int incX;
extern int i;
extern int j;
extern  int nonunit;
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
double temp_storage[N > 0 ? N : 1]; // Local storage to break WAW and WAR dependencies
for (i = N; i > 0 && i--;) {
    double temp = 0.;
    const int j_min = (K > i ? 0 : i - K);
    const int j_max = i;
    int jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX))) + j_min * incX;
    for (j = j_min; j < j_max; j++) {
        temp += X[jx] * A[lda * j + (i - j)];
        jx += incX;
    }
    temp_storage[i] = temp; // Store intermediate result to eliminate write-after-write (WAW) dependency on X[ix]
}
// Second pass: apply stored results with reverse index update (loop-carried dependency now broken)
int local_ix = ix;
for (i = N; i > 0 && i--;) {
    if (nonunit) {
        X[local_ix] = temp_storage[i] + X[local_ix] * A[lda * i + 0];
    } else {
        X[local_ix] += temp_storage[i];
    }
    local_ix -= incX;
}
}
