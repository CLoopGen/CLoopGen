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

extern MAT *A;
extern int k;
extern int _usr_j0;
extern double beta;
extern double nu1;
extern double nu2;
extern double nu3;
extern double ip;
extern double prod;
extern int j;
extern int n;

// Variable name mappings to avoid conflicts with system symbols
#define j0 _usr_j0



void loop(){
    // Variant 2: Consecutive Memory Layout Emulation via Base Pointer and Indexing
    // Assuming row-major layout and that data is stored consecutively in memory from base
    // Use flat indexing into contiguous memory block to improve spatial locality

    double *base_ptr = (A)->base;  // Assume base points to start of flat storage
    u_int cols = (A)->max_n;
    u_int offset_k   = k * cols;
    u_int offset_k1 = (k + 1) * cols;
    u_int offset_k2 = (k + 2) * cols;

    for (j = j0; j < n; j++) {
        // Convert 2D access to 1D consecutive access
        double val0 = base_ptr[offset_k   + j];
        double val1 = base_ptr[offset_k1 + j];
        double val2 = base_ptr[offset_k2 + j];

        ip = nu1 * val0 + nu2 * val1 + nu3 * val2;
        prod = ip * beta;

        base_ptr[offset_k   + j] += (-prod * nu1);
        base_ptr[offset_k1 + j] += (-prod * nu2);
        base_ptr[offset_k2 + j] += (-prod * nu3);
    }
}
