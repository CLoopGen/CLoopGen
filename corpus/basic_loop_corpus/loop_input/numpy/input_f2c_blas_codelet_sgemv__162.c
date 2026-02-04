#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef float real;

integer *m;
real *alpha;
real *a;
real *x;
real *y;
integer *incy;
integer a_dim1;
integer i__1;
integer i__2;
integer i__;
integer j;
integer jy;
real temp;

static real alpha_val;
static integer m_val;
static integer incy_val;
static integer i__1_val;

#define A_ROWS 2048
#define A_COLS 512

static real *a_data;
static real *x_data;
static real *y_data;

void init_vars() {
    m_val = A_ROWS;
    m = &m_val;

    alpha_val = 1.5f;
    alpha = &alpha_val;

    incy_val = 1;
    incy = &incy_val;

    i__1_val = A_COLS;
    i__1 = i__1_val;

    a_dim1 = A_ROWS;

    a_data = (real*)calloc(A_ROWS * A_COLS, sizeof(real));
    x_data = (real*)calloc(A_ROWS, sizeof(real));
    y_data = (real*)calloc(A_COLS, sizeof(real));

    if (!a_data || !x_data || !y_data) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < A_ROWS; ++i) {
        x_data[i] = (real)(i % 100) * 0.5f;
        for (int j = 0; j < A_COLS; ++j) {
            a_data[i + j * A_ROWS] = (real)((i + j) % 200) * 0.1f;
        }
    }

    for (int j = 0; j < A_COLS; ++j) {
        y_data[j] = (real)(j % 50) * 0.2f;
    }

    a = a_data;
    x = x_data;
    y = y_data;

    jy = 0;
    temp = 0.0f;
}