#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

typedef float real;
typedef int integer;

real *e;
integer *info;
integer i__1;
integer i__;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB of data for sufficient runtime (~0.01 sec on modern CPU)

    e = (real*)aligned_alloc(32, (data_size + 1) * sizeof(real));
    if (!e) exit(1);

    for (size_t i = 0; i <= data_size; ++i) {
        e[i] = (real)((double)rand() / RAND_MAX - 0.5); // random values around zero
    }

    info = (integer*)malloc(sizeof(integer));
    if (!info) exit(1);
    *info = 0;

    i__1 = (integer)data_size;
    i__ = 0;
}