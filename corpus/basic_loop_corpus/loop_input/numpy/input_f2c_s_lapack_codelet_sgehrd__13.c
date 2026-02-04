#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef float real;

integer *ihi;
real *tau;
integer i__1;
integer i__;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB of float data to target ~0.01 sec runtime

    tau = (real *)calloc(data_size, sizeof(real));
    if (!tau) exit(1);

    ihi = (integer *)malloc(sizeof(integer));
    if (!ihi) exit(1);
    *ihi = 1;

    i__1 = data_size - 1;
}