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
doublereal tau = 0.0;

integer i__storage = 0;
integer *i__ = &i__storage;
doublereal *d__ = NULL;
doublereal *delta = NULL;

static const size_t DATA_SIZE_MB = 64;
static const size_t ARRAY_LENGTH = (DATA_SIZE_MB * (1 << 20)) / sizeof(doublereal);

void init_vars() {
    i__1 = (integer)ARRAY_LENGTH - 1;
    *i__ = 1;
    tau = 3.14159;

    d__ = (doublereal*)aligned_alloc(32, ARRAY_LENGTH * sizeof(doublereal));
    delta = (doublereal*)aligned_alloc(32, ARRAY_LENGTH * sizeof(doublereal));

    if (!d__ || !delta) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < ARRAY_LENGTH; ++idx) {
        d__[idx] = (doublereal)(idx + 1) * 0.5;
        delta[idx] = 0.0;
    }

    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    while (1) {
        for (j = 1; j <= i__1; ++j) {
            delta[j] = d__[j] - d__[*i__] - tau;
        }
        clock_gettime(CLOCK_MONOTONIC, &end);
        long elapsed_ns = (end.tv_sec - start.tv_sec) * 1000000000 + (end.tv_nsec - start.tv_nsec);
        if (elapsed_ns >= 10000000) break;
    }

    for (size_t idx = 0; idx < ARRAY_LENGTH; ++idx) {
        d__[idx] = (doublereal)(idx + 1) * 1.23;
        delta[idx] = 0.0;
    }
}