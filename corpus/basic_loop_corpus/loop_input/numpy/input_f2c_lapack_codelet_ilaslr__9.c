#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

typedef int integer;
typedef float real;

integer *m;
real *a;
integer a_dim1;
integer ret_val;
integer i__1;
integer i__;
integer j;

static real *a_data = NULL;
static integer m_value;

void init_vars() {
    const size_t target_bytes = 64 * 1024 * 1024; // Aim for ~64 MB of data
    a_dim1 = (integer)sqrt((double)target_bytes / sizeof(real));
    i__1 = a_dim1 / 2;
    if (i__1 < 1) i__1 = 1;

    m_value = a_dim1;
    m = &m_value;

    size_t a_size = (size_t)(a_dim1 + 1) * (size_t)(a_dim1 + 1);
    a_data = (real *)calloc(a_size, sizeof(real));
    if (!a_data) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(1);
    }
    a = a_data - 1 - a_dim1; // Adjust base pointer to allow 1-based indexing: a[i__ + j * a_dim1]

    for (integer j = 1; j <= i__1; ++j) {
        for (integer i = *m; i >= 1; --i) {
            a[i + j * a_dim1] = (real)rand() / RAND_MAX;
        }
    }

    ret_val = 0;
    i__ = 0;
    j = 0;
}