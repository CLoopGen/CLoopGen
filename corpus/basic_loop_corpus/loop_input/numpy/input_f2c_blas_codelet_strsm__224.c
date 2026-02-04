#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

typedef int integer;
typedef float real;
typedef int logical;

integer *m;
real *alpha;
real *a;
real *b;
integer a_dim1;
integer b_dim1;
integer i__1;
integer i__2;
integer i__;
integer j;
integer k;
real temp;
logical nounit;

static real *a_data = NULL;
static real *b_data = NULL;

void init_vars() {
    const int M = 512;  
    const int N = 512;  

    m = (integer*)malloc(sizeof(integer));
    alpha = (real*)malloc(sizeof(real));
    *m = M;
    *alpha = 1.234f;
    a_dim1 = M;
    b_dim1 = N;
    i__1 = N;
    nounit = 1;

    size_t a_size = (size_t)M * M * sizeof(real);
    size_t b_size = (size_t)M * N * sizeof(real);

    a_data = (real*)calloc(M * M, sizeof(real));
    b_data = (real*)calloc(M * N, sizeof(real));

    if (!a_data || !b_data) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    a = a_data;
    b = b_data;

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < M; ++j) {
            a[i + j * a_dim1] = (i == j) ? 2.0f : ((i < j) ? 0.1f * (rand() / (float)RAND_MAX) : 0.0f);
        }
    }

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            b[i + j * b_dim1] = 1.0f + 0.1f * (rand() / (float)RAND_MAX);
        }
    }

    i__ = 0;
    j = 0;
    k = 0;
    i__2 = 0;
    temp = 0.0f;
}