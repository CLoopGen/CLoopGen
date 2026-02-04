#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

typedef int integer;
typedef double doublereal;
typedef int logical;

integer *n;
doublereal *a;
doublereal *x;
integer a_dim1;
integer i__1;
integer i__2;
integer i__;
integer j;
doublereal temp;
logical nounit;

#define DATA_SIZE_MB 64
#define TOTAL_ELEMENTS (DATA_SIZE_MB * (1 << 20) / sizeof(doublereal))

static doublereal *a_storage;
static doublereal *x_storage;
static integer n_value;

void init_vars() {
    const size_t max_n = (size_t)sqrt(TOTAL_ELEMENTS * sizeof(doublereal) / sizeof(doublereal)) + 1;
    n_value = (integer)(max_n > 10000 ? 10000 : max_n - 1);
    if (n_value < 100) n_value = 100;

    a_dim1 = n_value;
    i__1 = n_value;
    nounit = 1;

    size_t a_size = (size_t)(a_dim1 + 1) * (size_t)(i__1 + 1);
    size_t x_size = (size_t)(n_value + 1);

    a_storage = (doublereal*)calloc(a_size, sizeof(doublereal));
    x_storage = (doublereal*)calloc(x_size, sizeof(doublereal));

    if (!a_storage || !x_storage) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (integer idx = 1; idx <= n_value; ++idx) {
        x_storage[idx] = sin(idx);
        for (integer jdx = 1; jdx <= idx; ++jdx) {
            a_storage[idx + jdx * a_dim1] = cos(idx * jdx);
        }
        a_storage[idx + idx * a_dim1] += 2.0;
    }

    a = a_storage;
    x = x_storage;
    n = &n_value;
}