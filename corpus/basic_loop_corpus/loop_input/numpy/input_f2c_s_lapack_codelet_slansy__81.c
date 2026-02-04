#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef int integer;
typedef float real;
typedef double doublereal;

integer *n;
real *a;
integer a_dim1;
integer i__1;
integer i__2;
real r__1;
real r__2;
real r__3;
integer i__;
integer j;
real value;

static real *a_data = NULL;
static const size_t data_size = 1 << 20; // 1MB of data (~262k elements for float)

void init_vars() {
    // Allocate space for a matrix of size up to data_size / sizeof(real)
    size_t total_elements = data_size / sizeof(real);
    a_data = (real*)calloc(total_elements, sizeof(real));
    if (!a_data) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(1);
    }

    // Set matrix dimensions: assume square matrix for simplicity
    *n = (integer)sqrt(total_elements);
    a_dim1 = *n;  // leading dimension
    i__1 = *n;     // outer loop bound

    // Initialize a with random positive and negative values to allow meaningful max(abs()) computation
    for (size_t idx = 0; idx < total_elements; ++idx) {
        a_data[idx] = (real)(rand() % 100 - 50); // values between -50 and 50
    }

    // Point external 'a' to allocated matrix
    a = a_data;

    // Initialize value to 0.0 or small base
    value = 0.0f;
}

// Define all extern variables after init_vars ensures allocation
integer *n = &(struct { integer n_; }){ .n_ = 0 }.n_;
real *a = NULL;
integer a_dim1 = 0;
integer i__1 = 0;
integer i__2 = 0;
real r__1 = 0.0f;
real r__2 = 0.0f;
real r__3 = 0.0f;
integer i__ = 0;
integer j = 0;
real value = 0.0f;