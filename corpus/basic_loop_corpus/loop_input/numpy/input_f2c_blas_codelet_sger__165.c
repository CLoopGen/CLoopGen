#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef int integer;
typedef float real;

integer *m;
real *alpha;
real *x;
integer *incx;
real *y;
integer *incy;
real *a;
integer a_dim1;
integer i__1;
integer i__2;
integer i__;
integer j;
integer ix;
integer jy;
integer kx;
real temp;

#define M_SIZE 2048
#define N_SIZE 512

void init_vars() {
    // Allocate and initialize m
    m = (integer*)malloc(sizeof(integer));
    *m = M_SIZE;

    // Allocate and initialize alpha
    alpha = (real*)malloc(sizeof(real));
    *alpha = 1.5f;

    // Allocate and initialize incx
    incx = (integer*)malloc(sizeof(integer));
    *incx = 1;

    // Allocate and initialize incy
    incy = (integer*)malloc(sizeof(integer));
    *incy = 1;

    // Allocate and initialize a_dim1 (leading dimension of matrix a)
    a_dim1 = M_SIZE;

    // Allocate and initialize i__1 (loop bound for j, corresponds to N_SIZE)
    i__1 = N_SIZE;

    // Allocate arrays
    x = (real*)calloc(M_SIZE * abs(*incx), sizeof(real));
    y = (real*)calloc(N_SIZE * abs(*incy), sizeof(real));
    a = (real*)calloc(M_SIZE * N_SIZE, sizeof(real));

    // Initialize x with non-zero values
    for (int i = 0; i < M_SIZE; ++i) {
        x[i] = sinf((float)i);
    }

    // Initialize y with mixed zero and non-zero values (~50% non-zero)
    for (int j = 0; j < N_SIZE; ++j) {
        y[j] = (j % 2 == 0) ? cosf((float)j) : 0.0f;
    }

    // Set initial indices
    jy = 0;
    kx = 0;

    // Ensure temp is initialized
    temp = 0.0f;

    // Initialize a matrix with some baseline values
    for (int i = 0; i < M_SIZE; ++i) {
        for (int j = 0; j < N_SIZE; ++j) {
            a[i + j * a_dim1] = (real)(i + j) / (M_SIZE + N_SIZE);
        }
    }
}