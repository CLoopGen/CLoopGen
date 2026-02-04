#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double doublereal;
typedef int integer;

doublereal *work;
integer i__1;
integer i__;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // ~64MB of data for ~0.01 sec runtime
    work = (doublereal *)calloc(data_size / sizeof(doublereal), sizeof(doublereal));
    i__1 = (integer)(data_size / sizeof(doublereal)) - 1;
    i__ = 1;
}