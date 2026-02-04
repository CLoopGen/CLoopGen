#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

typedef float real;
typedef int integer;

real *r__;
integer i__1;
integer i__;
real safmx2;

real *array_data;
size_t array_size;

void init_vars() {
    const double target_time = 0.01;
    double start_time, end_time;
    clock_t begin, finish;

    array_size = (size_t)(16 * 1024 * 1024 / sizeof(real)); 
    array_data = (real*)calloc(array_size, sizeof(real));
    if (!array_data) {
        exit(1);
    }

    for (size_t i = 0; i < array_size; ++i) {
        array_data[i] = 1.0f + (i % 100);
    }

    r__ = &array_data[0];
    safmx2 = 1.000001f;
    i__1 = (integer)(target_time * 1e8);
    if (i__1 <= 0) i__1 = 1;

    begin = clock();
    for (long long iter = 0; iter < 1; ++iter) {
        for (i__ = 1; i__ <= i__1; ++i__) {
            *r__ *= safmx2;
        }
    }
    finish = clock();

    double elapsed = ((double)(finish - begin)) / CLOCKS_PER_SEC;
    if (elapsed < target_time && i__1 < 100000000) {
        i__1 = (integer)(i__1 * target_time / (elapsed > 0 ? elapsed : 1e-9));
        if (i__1 > 100000000) i__1 = 100000000;
    }

    r__ = &array_data[0];
}