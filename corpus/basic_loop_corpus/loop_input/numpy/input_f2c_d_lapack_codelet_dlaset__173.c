#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

typedef int integer;
typedef double doublereal;

integer *m;
doublereal *alpha;
doublereal *a;
integer a_dim1;
integer i__1;
integer i__2;
integer i__;
integer j;

void init_vars() {
    const integer size_m = 5000;
    const integer size_n = 5000;

    m = (integer*)malloc(sizeof(integer));
    *m = size_m;
    a_dim1 = size_m;

    alpha = (doublereal*)malloc(sizeof(doublereal));
    *alpha = 3.14159;

    a = (doublereal*)calloc((size_t)(a_dim1 + 1) * (size_t)(size_n + 1), sizeof(doublereal));

    i__1 = size_n;

    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    for (j = 1; j <= i__1; ++j) {
        i__2 = *m;
        for (i__ = j + 1; i__ <= i__2; ++i__) {
            a[i__ + j * a_dim1] = *alpha;
        }
    }

    clock_gettime(CLOCK_MONOTONIC, &end);
    double elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;

    if (elapsed < 0.01) {
        const integer scale_factor = (integer)ceil(sqrt(0.01 / elapsed));
        free(a);
        free(m);
        free(alpha);

        *m = size_m * scale_factor;
        a_dim1 = *m;
        i__1 = size_n * scale_factor;

        m = (integer*)malloc(sizeof(integer));
        *m = size_m * scale_factor;
        a_dim1 = *m;

        alpha = (doublereal*)malloc(sizeof(doublereal));
        *alpha = 3.14159;

        a = (doublereal*)calloc((size_t)(a_dim1 + 1) * (size_t)(i__1 + 1), sizeof(doublereal));
    }
}