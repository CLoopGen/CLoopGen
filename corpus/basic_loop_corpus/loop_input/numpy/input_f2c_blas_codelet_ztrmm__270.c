#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef double doublereal;

typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;

typedef int logical;

integer *m;
doublecomplex *alpha;
doublecomplex *a;
doublecomplex *b;
integer a_dim1;
integer b_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__4;
integer i__5;
integer i__6;
doublecomplex z__1;
doublecomplex z__2;
integer i__;
integer j;
integer k;
doublecomplex temp;
logical nounit;

static doublecomplex *a_data = NULL;
static doublecomplex *b_data = NULL;
static integer m_storage;
static doublecomplex alpha_storage;

void init_vars() {
    // Problem size parameters
    const integer M = 512;
    const integer N = 512;  // corresponds to i__1

    // Allocate memory for arrays with proper bounds
    a_dim1 = M;
    b_dim1 = M;
    i__1 = N;
    m = &m_storage;
    *m = M;
    alpha = &alpha_storage;
    alpha->r = 1.0;
    alpha->i = 0.5;
    nounit = 1;

    // Allocate and initialize a: M x M matrix
    a_data = (doublecomplex*)calloc(M * M, sizeof(doublecomplex));
    if (!a_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    for (integer idx = 0; idx < M * M; ++idx) {
        a_data[idx].r = (doublereal)(rand() % 100) / 100.0;
        a_data[idx].i = (doublereal)(rand() % 100) / 100.0;
    }
    a = a_data;

    // Allocate and initialize b: M x N matrix
    b_data = (doublecomplex*)calloc(M * N, sizeof(doublecomplex));
    if (!b_data) {
        fprintf(stderr, "Allocation failed\n");
        free(a_data);
        exit(1);
    }
    for (integer idx = 0; idx < M * N; ++idx) {
        b_data[idx].r = (doublereal)(rand() % 100) / 100.0;
        b_data[idx].i = (doublereal)(rand() % 100) / 100.0;
    }
    b = b_data;

    // Initialize temporaries
    temp.r = 0.0;
    temp.i = 0.0;
    z__1.r = 0.0;
    z__1.i = 0.0;
    z__2.r = 0.0;
    z__2.i = 0.0;
    i__ = 0;
    j = 0;
    k = 0;
}