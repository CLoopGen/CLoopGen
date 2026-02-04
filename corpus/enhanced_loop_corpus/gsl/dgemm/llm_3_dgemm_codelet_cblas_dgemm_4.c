#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int K;
extern  double alpha;
extern double *C;
extern  int ldc;
extern int i;
extern int j;
extern int k;
extern int n1;
extern int n2;
extern int ldf;
extern int ldg;
extern  double *F;
extern  double *G;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 0; k < K; k++) {
    const double alpha_k = alpha * F[ldf * k]; // base contribution from F
    const ptrdiff_t g_offset = ldg * k;
    const ptrdiff_t c_offset = ldc * 0; // base row in C
    for (i = 0; i < n1; i++) {
        const ptrdiff_t f_idx = ldf * k + i;
        const double temp = alpha * F[f_idx];
        if (temp != 0.) {
            double * restrict c_row = &C[c_offset + i];
            const double * restrict g_row = &G[g_offset];
            for (j = 0; j < n2; j += 4) {
                // Unrolled and consecutive access to improve spatial locality
                if (j + 3 < n2) {
                    c_row[j    ] += temp * g_row[j    ];
                    c_row[j + 1] += temp * g_row[j + 1];
                    c_row[j + 2] += temp * g_row[j + 2];
                    c_row[j + 3] += temp * g_row[j + 3];
                } else {
                    for (int jj = j; jj < n2; jj++) {
                        c_row[jj] += temp * g_row[jj];
                    }
                    break;
                }
            }
        }
    }
}
}
