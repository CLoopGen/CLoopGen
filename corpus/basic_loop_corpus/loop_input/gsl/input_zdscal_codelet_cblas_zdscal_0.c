#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N;
double alpha;
void *X;
int incX;
int i;
int ix;

void init_vars() {
    // Set scalar values
    N = 10000000;  // 10M iterations to target ~0.01s runtime
    alpha = 1.5;
    incX = 2;  // typical stride

    // Allocate X as an array of double, size 2 * (max index used) to prevent out-of-bounds
    // Maximum index: 2*(ix) + 1 at last iteration
    // ix starts at 0 and increases by incX each iteration
    // Final ix value: ix_initial + (N-1)*incX
    // We assume ix starts at 0 in the loop context unless specified otherwise
    // So max offset: 2 * (ix_initial + (N-1)*incX) + 1
    // With ix_initial = 0 -> max index = 2*((N-1)*incX) + 1
    // But inside loop: index = 2*ix, so max index = 2 * ((N-1)*incX) + 1
    // Total doubles needed: 2 * ((N-1)*incX) + 2 (to be safe)

    int max_index = 2 * ((N - 1) * incX) + 2;
    X = aligned_alloc(32, max_index * sizeof(double));
    if (!X) exit(1);

    // Initialize ix to 0 for loop start
    ix = 0;

    // Initialize X data to avoid NaN or extreme values
    double *dx = (double *)X;
    for (int j = 0; j < max_index; j++) {
        dx[j] = 1.0;
    }
}