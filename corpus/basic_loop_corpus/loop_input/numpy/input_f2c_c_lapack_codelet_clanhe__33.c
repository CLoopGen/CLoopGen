#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>
#include <time.h>

typedef float real;
typedef double doublereal;

typedef struct {
    real r;
    real i;
} singlecomplex;

typedef int integer;

singlecomplex *a;
integer a_dim1;
integer i__1;
integer i__2;
real r__1;
integer i__;
real sum;
real absa;
real scale;

void init_vars() {
    const size_t total_data_size = 64 * 1024 * 1024; // Aim for ~64 MB of data
    a_dim1 = (integer)sqrt((double)total_data_size / sizeof(singlecomplex));
    i__1 = a_dim1; // Set loop bound to avoid out-of-bounds

    // Allocate array with padding to prevent access beyond allocated space
    a = (singlecomplex*)calloc((a_dim1 + 1) * (a_dim1 + 1), sizeof(singlecomplex));
    if (!a) {
        exit(1);
    }

    // Initialize computational variables
    sum = 1.0f;
    scale = 1e-3f;

    // Seed random number generator and initialize some diagonal elements
    srand((unsigned int)time(NULL));
    for (int i = 1; i <= i__1; ++i) {
        int idx = i + i * a_dim1;
        a[idx].r = ((float)rand() / RAND_MAX) * 2.0f - 1.0f; // Random in [-1, 1]
        a[idx].i = 0.0f;
    }

    // Ensure at least one large value to trigger scaling logic
    if (i__1 >= 1) {
        a[1 + 1 * a_dim1].r = 100.0f;
    }
}