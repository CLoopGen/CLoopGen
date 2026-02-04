#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef double doublereal;

integer *k;
doublereal *alpha;
doublereal *a;
doublereal *b;
doublereal *beta;
doublereal *c__;
integer a_dim1;
integer b_dim1;
integer c_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__;
integer j;
integer l;
doublereal temp1;
doublereal temp2;

static integer K;
static doublereal ALPHA;
static doublereal BETA;
static integer I__1;
static integer A_DIM1;
static integer B_DIM1;
static integer C_DIM1;

static doublereal *A_DATA;
static doublereal *B_DATA;
static doublereal *C_DATA;

void init_vars() {
    K = 500;
    ALPHA = 1.5;
    BETA = 1.0;
    I__1 = 500;
    A_DIM1 = K + 100;
    B_DIM1 = K + 100;
    C_DIM1 = I__1 + 100;

    k = &K;
    alpha = &ALPHA;
    beta = &BETA;
    i__1 = I__1;
    a_dim1 = A_DIM1;
    b_dim1 = B_DIM1;
    c_dim1 = C_DIM1;

    size_t a_size = (I__1 + 1) * (K + 1);
    size_t b_size = (I__1 + 1) * (K + 1);
    size_t c_size = (I__1 + 1) * (I__1 + 1);

    A_DATA = (doublereal*)calloc(a_size, sizeof(doublereal));
    B_DATA = (doublereal*)calloc(b_size, sizeof(doublereal));
    C_DATA = (doublereal*)calloc(c_size, sizeof(doublereal));

    if (!A_DATA || !B_DATA || !C_DATA) {
        exit(1);
    }

    for (int idx = 0; idx < a_size; ++idx) {
        A_DATA[idx] = (doublereal)(rand() % 100) / 100.0;
    }
    for (int idx = 0; idx < b_size; ++idx) {
        B_DATA[idx] = (doublereal)(rand() % 100) / 100.0;
    }
    for (int idx = 0; idx < c_size; ++idx) {
        C_DATA[idx] = (doublereal)(rand() % 100) / 100.0;
    }

    a = A_DATA;
    b = B_DATA;
    c__ = C_DATA;
}