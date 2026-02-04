#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef float real;

integer *k;
real *q;
real *s;
integer q_dim1;
integer s_dim1;
integer i__1;
integer i__2;
integer i__;
integer j;

static real *q_data;
static real *s_data;
static integer k_value;

void init_vars() {
    // Set dimensions and loop bounds
    q_dim1 = 5000;
    s_dim1 = 5000;
    i__1 = 5000;
    k_value = 5000;
    k = &k_value;

    // Allocate data arrays to be approximately 100MB each (5000*5000*sizeof(float) ≈ 100MB)
    q_data = (real*)calloc((size_t)(q_dim1 + 1) * (size_t)(i__1 + 1), sizeof(real));
    s_data = (real*)calloc((size_t)(s_dim1 + 1) * (size_t)(i__1 + 1), sizeof(real));

    if (!q_data || !s_data) {
        exit(1);
    }

    q = q_data;
    s = s_data;

    // Initialize some sample values in q array
    for (integer idx = 1; idx <= i__1; ++idx) {
        for (integer jdx = 1; jdx <= k_value; ++jdx) {
            q[jdx + idx * q_dim1] = (real)(idx + jdx);
        }
    }
}

// Forward declaration of the loop function to avoid implicit declaration
void loop();