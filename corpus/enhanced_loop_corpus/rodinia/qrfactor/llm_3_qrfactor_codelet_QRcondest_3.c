#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    u_int m;
    u_int n;
    u_int max_m;
    u_int max_n;
    u_int max_size;
    double **me;
    double *base;
} MAT;

typedef struct {
    u_int dim;
    u_int max_dim;
    double *ve;
} VEC;

extern MAT *QR;
extern VEC *y;
extern double sum;
extern int i;
extern int j;
extern int limit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with reversed inner loop traversal (stride of 2, unrolled pattern)
    // Simulates non-unit stride access; useful for testing cache behavior or vectorization robustness
    double **me_QR = QR->me;
    double *ve_y = y->ve;
    for (i = limit - 1; i >= 0; i--) {
        sum = 0.;
        int offset = i + 1;
        int remainder = (limit - offset) % 2;
        // Handle unaligned start if needed
        if (remainder && (offset < limit)) {
            sum += me_QR[i][offset] * ve_y[offset];
            offset++;
        }
        // Stride-2 access in the inner loop
        for (j = offset; j < limit; j += 2) {
            sum += me_QR[i][j] * ve_y[j];
            if (j + 1 < limit) {
                sum += me_QR[i][j + 1] * ve_y[j + 1];
            }
        }
        ve_y[i] = (sum >= 0.) ? 1. : -1.;
        ve_y[i] = (me_QR[i][i] >= 0.) ? ve_y[i] : -ve_y[i];
    }
}
