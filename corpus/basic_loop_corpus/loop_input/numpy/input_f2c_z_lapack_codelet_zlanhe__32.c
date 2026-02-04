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
    size_t data_size = 64 * 1024 * 1024; // ~64MB of data for sufficient runtime (~0.01 sec)
    work = (doublereal *)calloc(data_size, sizeof(doublereal));
    if (!work) exit(1);
    i__1 = data_size - 1;
    i__ = 0;
}