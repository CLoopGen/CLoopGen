#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>

typedef int integer;
typedef double doublereal;

integer *k;
doublereal *alpha;
doublereal *a;
doublereal *beta;
doublereal *c__;
integer a_dim1;
integer c_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__;
integer j;
integer l;
doublereal temp;

static doublereal alpha_val = 1.5;
static doublereal beta_val = 0.8;

static integer k_val;
static integer i__1_val;
static integer a_dim1_val;
static integer c_dim1_val;

static doublereal *a_data;
static doublereal *c_data;

void init_vars() {
    // Set problem size to achieve roughly 0.01s runtime on modern CPU
    // The triple loop has O(i__1^2 * k) complexity, with i__1 ~ N and k ~ N
    // We aim for total data size around 64-128MB for reasonable performance
    k_val = 1024;
    i__1_val = 1024;
    
    a_dim1_val = k_val;   // a is indexed [l + i__ * a_dim1], l <= k, i__ <= i__1
    c_dim1_val = i__1_val;

    // Allocate arrays with proper sizes
    a_data = (doublereal*)calloc((k_val * i__1_val), sizeof(doublereal));
    c_data = (doublereal*)calloc((i__1_val * i__1_val), sizeof(doublereal));

    if (!a_data || !c_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize a with some data to avoid zero values
    for (int idx = 0; idx < k_val * i__1_val; ++idx) {
        a_data[idx] = (doublereal)(rand() % 100) / 100.0;
    }

    // Initialize c__ with some base values
    for (int idx = 0; idx < i__1_val * i__1_val; ++idx) {
        c_data[idx] = (doublereal)(rand() % 100) / 200.0;
    }

    // Assign external pointers
    k = &k_val;
    alpha = &alpha_val;
    a = a_data;
    beta = &beta_val;
    c__ = c_data;
    a_dim1 = a_dim1_val;
    c_dim1 = c_dim1_val;
    i__1 = i__1_val;
}