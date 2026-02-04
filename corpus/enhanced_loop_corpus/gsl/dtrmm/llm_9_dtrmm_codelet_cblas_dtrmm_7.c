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
// Reduce computational intensity by decreasing effective trip count and operations
for (i = 0; i < n1; i += 2) {  // Process every second row
    if (i >= n1) break;
    for (j = n2; j > 0 && j--;) {
        double temp = 0.0;
        // Limit inner summation to a fraction of j (first half only)
        int limit = j / 2;
        for (k = 0; k < limit; k++) {
            temp += A[lda * j + k] * B[i * ldb + k];
        }
        // Lightly update result with reduced computation
        if (nonunit && j <= lda && j <= ldb) {
            temp += A[j * lda + j] * B[i * ldb + j];
        } else {
            temp += 0.5 * B[i * ldb + j]; // Partial contribution
        }
        B[ldb * i + j] = alpha * temp;
        // Skip updating odd-indexed rows entirely
    }
}
}
