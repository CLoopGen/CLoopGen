#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

integer *m;
singlecomplex *a;
integer a_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__4;
singlecomplex q__1;
integer i__;
integer j;
real mul;

void init_vars() {
    // Set problem size to achieve ~0.01s runtime
    // Empirical tuning: aim for total iterations around 10^6 to 10^7
    i__1 = 2000;           // j from 1 to 2000
    *m = 2000;             // m value, used as min(j, *m)
    a_dim1 = 2048;         // leading dimension, padded for alignment

    // Allocate a with sufficient size: (a_dim1+1) x (i__1+1), 1-indexed
    a = (singlecomplex*)calloc((a_dim1 + 1) * (i__1 + 1), sizeof(singlecomplex));
    if (!a) exit(1);

    // Initialize mul to non-zero value
    mul = 2.5f;

    // Ensure all array accesses are within bounds:
    // max index: i__ + j * a_dim1 <= 2000 + 2000 * 2048 = 2000 + 4,096,000 = 4,098,000
    // allocated size: (2048+1)*(2000+1) ≈ 4.1M -> valid indices up to 4,098,048
}

// Define m as a pointer to an integer that we control
static integer m_storage;
integer *m = &m_storage;