#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double alpha;
extern  double *A;
extern  int lda;
extern double *B;
extern  int ldb;
extern int i;
extern int j;
extern int k;
extern int n1;
extern int n2;
extern  int nonunit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
double temp_storage[256]; // Local buffer to absorb writes and break WAW/WAR hazards
int max_local_j = (n2 < 256) ? n2 : 255;

for (i = 0; i < n1; i++) {
    // First, compute all temp values without writing back to B
    for (j = 0; j < max_local_j; j++) {
        double temp = 0.;
        for (k = 0; k < j; k++) {
            temp += A[lda * k + j] * B[i * ldb + k];
        }
        if (nonunit) {
            temp += A[j * lda + j] * B[i * ldb + j];
        } else {
            temp += B[i * ldb + j];
        }
        temp_storage[j] = alpha * temp;
    }
    // Now update B in forward order using precomputed values
    for (j = 0; j < max_local_j; j++) {
        B[ldb * i + j] = temp_storage[j];
    }
}
}
