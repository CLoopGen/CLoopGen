#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>

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

static doublereal alpha_val = 1.5;
static doublereal beta_val = 0.5;

static integer k_val = 128;
static integer n_val = 512;

static integer a_size;
static integer b_size;
static integer c_size;

static doublereal *a_data;
static doublereal *b_data;
static doublereal *c_data;

void init_vars() {
    k = &k_val;
    alpha = &alpha_val;
    beta = &beta_val;

    a_dim1 = k_val;
    b_dim1 = k_val;
    c_dim1 = n_val;

    i__1 = n_val;

    a_size = (k_val + 1) * (n_val + 1);
    b_size = (k_val + 1) * (n_val + 1);
    c_size = (n_val + 1) * (n_val + 1);

    a_data = (doublereal*)calloc(a_size, sizeof(doublereal));
    b_data = (doublereal*)calloc(b_size, sizeof(doublereal));
    c_data = (doublereal*)calloc(c_size, sizeof(doublereal));

    if (!a_data || !b_data || !c_data) {
        exit(1);
    }

    a = a_data;
    b = b_data;
    c__ = c_data;

    for (integer idx = 0; idx < a_size; ++idx) {
        a_data[idx] = (doublereal)(idx % 128) / 64.0;
    }
    for (integer idx = 0; idx < b_size; ++idx) {
        b_data[idx] = (doublereal)(idx % 128) / 64.0;
    }
    for (integer idx = 0; idx < c_size; ++idx) {
        c_data[idx] = (doublereal)(idx % 128) / 64.0;
    }
}