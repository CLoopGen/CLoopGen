#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
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
extern int n1;
extern int n2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
double *C_base = C;
for (i = 0; i < n1; i++) {
    double *A_row = &A[i * lda];  // Base pointer to row i of A
    double *B_col = &B[i];        // Base pointer to column i of B (assuming column-major layout)
    double temp1_scalar = alpha * B_col[0 * ldb + i];  // Strided access in B
    double temp2 = 0.;

    for (j = 0; j < n2; j++) {
        C_base[j] += temp1_scalar * A_row[i];  // Direct use of base pointers with offset
        for (k = i + 1; k < n1; k++) {
            const double Aik = A_row[k];
            C_base[j] += Aik * temp1_scalar;
            temp2 += Aik * B_col[j * ldb + k];  // Strided access pattern in B
        }
        C_base[j] += alpha * temp2;
        C_base += ldc;  // Move C pointer to next row
    }
    C_base = &C[(i + 1) * ldc];  // Reset C_base for next i iteration
}
}
