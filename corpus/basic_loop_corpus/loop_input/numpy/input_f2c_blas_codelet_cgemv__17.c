#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

typedef int integer;

typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

integer *m;
singlecomplex *alpha;
singlecomplex *a;
singlecomplex *x;
integer *incx;
singlecomplex *y;
integer a_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__4;
integer i__5;
singlecomplex q__1;
singlecomplex q__2;
integer i__;
integer j;
integer jx;
singlecomplex temp;

#define M_SIZE 2048
#define N_SIZE 1024

static singlecomplex *a_data;
static singlecomplex *x_data;
static singlecomplex *y_data;
static integer m_value;
static integer incx_value;
static integer n_value;

void init_vars() {
    m_value = M_SIZE;
    n_value = N_SIZE;
    incx_value = 1;

    m = &m_value;
    incx = &incx_value;

    a_dim1 = M_SIZE;

    alpha = (singlecomplex*)malloc(sizeof(singlecomplex));
    alpha->r = 1.0f;
    alpha->i = 0.5f;

    a_data = (singlecomplex*)calloc(M_SIZE * N_SIZE, sizeof(singlecomplex));
    x_data = (singlecomplex*)calloc(N_SIZE, sizeof(singlecomplex));
    y_data = (singlecomplex*)calloc(M_SIZE, sizeof(singlecomplex));

    a = a_data;
    x = x_data;
    y = y_data;

    i__1 = n_value;
    jx = 0;

    for (int i = 0; i < N_SIZE; ++i) {
        x_data[i].r = sinf(i * 0.01f);
        x_data[i].i = cosf(i * 0.01f);
    }

    for (int i = 0; i < M_SIZE; ++i) {
        y_data[i].r = 0.0f;
        y_data[i].i = 0.0f;
    }

    for (int i = 0; i < M_SIZE * N_SIZE; ++i) {
        a_data[i].r = rand() / (real)RAND_MAX;
        a_data[i].i = rand() / (real)RAND_MAX;
    }
}