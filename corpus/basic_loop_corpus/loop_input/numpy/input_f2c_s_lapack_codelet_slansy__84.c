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
    size_t data_size = 64 * 1024 * 1024; // ~64MB of float data (~256M bytes)
    work = (real *)calloc(data_size, sizeof(real));
    if (!work) {
        exit(1);
    }
    i__1 = (integer)(data_size - 1); // Ensure work[i__] access is within bounds for i__ from 1 to i__1
}