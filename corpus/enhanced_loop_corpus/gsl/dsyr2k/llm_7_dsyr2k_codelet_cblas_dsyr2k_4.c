#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  int K;
extern  double alpha;
extern  double *A;
extern  int lda;
extern  double *B;
extern  int ldb;
extern double *C;
extern  int ldc;
extern int i;
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < N; j++) { // Reverse loop order: j now outer, i inner — changes loop-carried dependencies
    for (i = 0; i <= j; i++) { // Adjust bounds so that i <= j to preserve upper-triangle logic
        double temp = 0.0;
        for (k = K - 1; k >= 0; k--) { // Reverse the inner loop direction — modifies RAW/WAR patterns
            temp += (A[i * lda + k] * B[j * ldb + k] + B[i * ldb + k] * A[j * lda + k]);
        }
        C[i * ldc + j] += alpha * temp; // Write remains, but execution order affects potential vectorization
    }
}
}
