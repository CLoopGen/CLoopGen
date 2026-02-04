#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float real;
typedef int integer;

real *scale;
integer i__1;
integer i__;
integer k;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB of float data (~256M bytes)
    scale = (real*)calloc(data_size, sizeof(real));
    if (!scale) {
        exit(1);
    }

    k = 0;
    i__1 = data_size - 1;
}

// Ensure definitions are not optimized out
__attribute__((used)) void* get_scale() { return (void*)scale; }
__attribute__((used)) integer get_i1() { return i__1; }
__attribute__((used)) integer get_k() { return k; }