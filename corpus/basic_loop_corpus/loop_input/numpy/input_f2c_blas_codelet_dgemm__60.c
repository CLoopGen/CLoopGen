#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef double doublereal;

integer *m;
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
doublereal temp;

static integer s_m;
static integer s_k;
static integer s_n;
static doublereal s_alpha;
static doublereal s_beta;

static doublereal *a_data;
static doublereal *b_data;
static doublereal *c_data;

void init_vars() {
    s_m = 512;
    s_k = 256;
    s_n = 256;

    s_alpha = 1.5;
    s_beta = 0.8;

    m = &s_m;
    k = &s_k;
    alpha = &s_alpha;
    beta = &s_beta;

    a_dim1 = s_m;
    b_dim1 = s_k;
    c_dim1 = s_m;

    i__1 = s_n;
    i__2 = s_m;
    i__3 = s_m;

    size_t a_size = (size_t)s_m * (size_t)s_k * sizeof(doublereal);
    size_t b_size = (size_t)s_k * (size_t)s_n * sizeof(doublereal);
    size_t c_size = (size_t)s_m * (size_t)s_n * sizeof(doublereal);

    a_data = (doublereal*)calloc(1, a_size);
    b_data = (doublereal*)calloc(1, b_size);
    c_data = (doublereal*)calloc(1, c_size);

    if (!a_data || !b_data || !c_data) {
        exit(1);
    }

    a = a_data;
    b = b_data;
    c__ = c_data;

    for (integer idx = 0; idx < s_m * s_k; ++idx) {
        a_data[idx] = (doublereal)(idx % 100) / 100.0;
    }
    for (integer idx = 0; idx < s_k * s_n; ++idx) {
        b_data[idx] = (doublereal)((idx + 10) % 90) / 100.0;
    }
    for (integer idx = 0; idx < s_m * s_n; ++idx) {
        c_data[idx] = (doublereal)((idx + 20) % 80) / 100.0;
    }

    i__ = 0;
    j = 0;
    l = 0;
    temp = 0.0;
}