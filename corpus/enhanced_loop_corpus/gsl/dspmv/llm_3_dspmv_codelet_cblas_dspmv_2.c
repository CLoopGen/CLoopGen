#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  double alpha;
extern  double *Ap;
extern  double *X;
extern  int incX;
extern double *Y;
extern  int incY;
extern int i;
extern int j;
extern int ix;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reverse the loop iteration order (from bottom to top) to change memory access pattern
// This creates a backward traversal, potentially improving cache behavior in some contexts
for (i = N - 1; i >= 0; i--) {
    int rev_ix = ((incX) > 0 ? 0 : (N - 1) * (-incX)) + i * incX;
    int rev_iy = ((incY) > 0 ? 0 : (N - 1) * (-incY)) + i * incY;

    double tmp1 = alpha * X[rev_ix];
    double tmp2 = 0.;
    const int j_min = i + 1;
    const int j_max = N;

    // Use direct indexing with offset calculation preserved but adapted for reverse logic
    int ap_offset_base = (((((i) - 1) + 1) * (2 * (N) - ((i) - 1))) / 2);
    Y[rev_iy] += tmp1 * Ap[ap_offset_base + (i) - (i)];

    for (j = j_min; j < j_max; j++) {
        int ap_index = ap_offset_base + (j) - (i);
        int x_index = ((incX) > 0 ? 0 : (N - 1) * (-incX)) + j * incX;
        int y_index = ((incY) > 0 ? 0 : (N - 1) * (-incY)) + j * incY;

        const double apk = Ap[ap_index];
        Y[y_index] += tmp1 * apk;
        tmp2 += apk * X[x_index];
    }
    Y[rev_iy] += alpha * tmp2;
}
}
