#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double doublereal;
typedef int integer;

doublereal *work;
integer i__1;
doublereal d__1;
doublereal d__2;
integer i__;
doublereal value;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB to target ~0.01 sec runtime
    work = (doublereal*)aligned_alloc(32, data_size);
    if (!work) exit(1);

    for (size_t i = 0; i < data_size / sizeof(doublereal); ++i) {
        work[i] = (doublereal)(rand() % 1000) / 10.0;
    }

    i__1 = data_size / sizeof(doublereal) - 1;
    value = 50.0;
    d__1 = 0.0;
    d__2 = 0.0;
    i__ = 0;
}