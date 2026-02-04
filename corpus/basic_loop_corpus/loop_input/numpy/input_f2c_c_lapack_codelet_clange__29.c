#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float real;
typedef int integer;

real *work;
integer i__1;
integer i__;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // ~64MB of data for sufficient runtime (~0.01 sec on modern CPUs)
    work = (real*)calloc(data_size, sizeof(real));
    if (!work) {
        exit(1);
    }
    i__1 = data_size - 1; // Ensure work[i__] access is within bounds for i__ from 1 to i__1
}