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
    // Variant 2: Reduced trip count and modified loop bounds to decrease work, with simplified computation
    // Process only every other row to reduce total iterations by ~50%
    for (i = (limit - 1) & ~1; i >= 0; i -= 2) {  // Round down to nearest even index, step by 2
        // Compute for index i
        sum = 0.;
        for (j = i + 1; j < limit; j++) {
            sum += QR->me[i][j] * y->ve[j];
        }
        y->ve[i] = (sum >= 0.) ? 1. : -1.;
        y->ve[i] = (QR->me[i][i] >= 0.) ? y->ve[i] : -y->ve[i];

        // Also process i-1 if within bounds
        if (i > 0) {
            i--;  // Decrement here since for-loop will subtract 2
            sum = 0.;
            for (j = i + 1; j < limit; j++) {
                sum += QR->me[i][j] * y->ve[j];
            }
            y->ve[i] = (sum >= 0.) ? 1. : -1.;
            y->ve[i] = (QR->me[i][i] >= 0.) ? y->ve[i] : -y->ve[i];
        }
    }
    // Note: If original limit was odd, the smallest index (0 or 1) is still handled due to rounding logic
}
