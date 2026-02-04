#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

typedef int integer;
typedef double doublereal;

integer i__1 = 0;
integer j = 0;
doublereal midpt = 0.0;

integer *i__ = NULL;
doublereal *d__ = NULL;
doublereal *delta = NULL;

void init_vars() {
    const size_t data_size_mb = 64;
    const size_t element_size = sizeof(doublereal);
    const size_t array_length = (data_size_mb * 1024 * 1024) / element_size;

    i__1 = (integer)array_length;
    if (i__1 <= 0) i__1 = 1;

    i__ = (integer*)malloc(sizeof(integer));
    if (!i__) exit(1);
    *i__ = 1;

    d__ = (doublereal*)calloc(array_length + 1, sizeof(doublereal));
    if (!d__) exit(1);

    delta = (doublereal*)malloc((array_length + 1) * sizeof(doublereal));
    if (!delta) exit(1);

    midpt = 1.5;

    for (size_t idx = 1; idx <= (size_t)i__1; ++idx) {
        d__[idx] = (doublereal)(idx * 2);
    }

    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    for (int warmup = 0; warmup < 5; ++warmup) {
        for (j = 1; j <= i__1; ++j) {
            delta[j] = d__[j] - d__[*i__] - midpt;
        }
    }

    clock_gettime(CLOCK_MONOTONIC, &end);
    double elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;

    if (elapsed > 0) {
        double target_time = 0.01;
        double scale = target_time / (elapsed / 5.0);
        integer new_i__1 = (integer)((double)i__1 * sqrt(scale));
        if (new_i__1 < 1) new_i__1 = 1;
        if (new_i__1 > (integer)array_length) new_i__1 = (integer)array_length;
        i__1 = new_i__1;
    }

    for (j = 1; j <= i__1; ++j) {
        delta[j] = 0.0;
    }
}