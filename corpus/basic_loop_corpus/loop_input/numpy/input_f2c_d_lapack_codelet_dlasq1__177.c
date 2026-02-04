#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double doublereal;
typedef int integer;

doublereal *work;
integer i__1;
doublereal d__1;
integer i__;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // 64 MB of data for ~0.01 sec runtime
    work = (doublereal*)aligned_alloc(32, data_size);
    if (!work) exit(1);

    for (size_t i = 0; i < data_size / sizeof(doublereal); ++i) {
        work[i] = (doublereal)(i % 1000) / 100.0;
    }

    i__1 = (integer)(data_size / sizeof(doublereal)) - 1;
    i__ = 1;
}