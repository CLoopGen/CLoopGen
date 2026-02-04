#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef int integer;
typedef float real;

integer *m;
real *a;
real *b;
integer a_dim1;
integer b_dim1;
integer i__1;
integer i__2;
integer i__;
integer j;

void init_vars() {
    const integer size = 8192;
    a_dim1 = size;
    b_dim1 = size;
    i__1 = size - 1;
    m = (integer*)malloc(sizeof(integer));
    *m = size;

    size_t total_elements = (size_t)size * size;
    a = (real*)aligned_alloc(32, total_elements * sizeof(real));
    b = (real*)aligned_alloc(32, total_elements * sizeof(real));

    if (!a || !b || !m) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < total_elements; ++idx) {
        a[idx] = (real)(rand() / (double)RAND_MAX);
        b[idx] = 0.0f;
    }
}