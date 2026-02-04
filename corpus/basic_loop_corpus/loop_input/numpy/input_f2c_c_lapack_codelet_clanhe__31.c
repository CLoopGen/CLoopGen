#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

typedef float real;
typedef int integer;
typedef double doublereal;

real *work;
integer i__1;
real r__1;
real r__2;
integer i__;
real value;

void init_vars() {
    const uint64_t target_time_ns = 10000000; // 10 ms in nanoseconds
    const uint64_t clock_freq_guess = 3000000000ULL; // 3 GHz
    const size_t iterations_guess = target_time_ns * clock_freq_guess / 1000000000ULL / 10; // Rough instruction estimate

    i__1 = (integer)(iterations_guess > 1000 ? iterations_guess : 1000);

    work = (real*)aligned_alloc(32, ((size_t)i__1 + 1) * sizeof(real));
    if (!work) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int i = 1; i <= i__1; ++i) {
        work[i] = (real)(rand() % 1000) / 10.0f;
    }

    value = (real)(rand() % 1000) / 10.0f;
    r__1 = 0.0f;
    r__2 = 0.0f;
    i__ = 0;
}