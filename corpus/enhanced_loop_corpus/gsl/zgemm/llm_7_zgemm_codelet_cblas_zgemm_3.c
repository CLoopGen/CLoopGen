#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int K;
extern void *C;
extern  int ldc;
extern int i;
extern int j;
extern int k;
extern int n1;
extern int n2;
extern int ldf;
extern int ldg;
extern int conjF;
extern int conjG;
extern  double *F;
extern  double *G;
extern  double alpha_real;
extern  double alpha_imag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reorder loops to change data access pattern and introduce new dependencies
for (k = 0; k < K; k++) {
    for (i = 0; i < n1; i++) {
        const double Fik_real = (((const double *)F)[2 * (ldf * i + k)]);
        const double Fik_imag = conjF * (((const double *)F)[2 * (ldf * i + k) + 1]);
        for (j = 0; j < n2; j++) {
            // Introduce WAR-like behavior by updating C in inner loop before full temp accumulation
            const double Gjk_real = (((const double *)G)[2 * (ldg * j + k)]);
            const double Gjk_imag = conjG * (((const double *)G)[2 * (ldg * j + k) + 1]);
            // Partial update of C without full reduction — changes semantics but preserves linearity
            const double prod_real = Fik_real * Gjk_real - Fik_imag * Gjk_imag;
            const double prod_imag = Fik_real * Gjk_imag + Fik_imag * Gjk_real;
            // Update C incrementally: introduces loop-carried dependence on C[i][j]
            ((double *)C)[2 * (ldc * i + j)] += alpha_real * prod_real - alpha_imag * prod_imag;
            ((double *)C)[2 * (ldc * i + j) + 1] += alpha_real * prod_imag + alpha_imag * prod_real;
        }
    }
}
// Note: This variant computes the same result only if alpha is real and no intermediate overwrites break correctness.
// To preserve semantics under general complex alpha, this would require pre-initialization or adjustment.
// As a mutation showing dependency shift (from k-reduction to immediate write), it illustrates a valid optimization variant.
}
