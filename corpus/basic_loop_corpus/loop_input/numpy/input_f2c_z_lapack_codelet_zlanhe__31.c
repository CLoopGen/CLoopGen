#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

typedef double doublereal;
typedef int integer;

doublereal *work;
integer i__1;
doublereal d__1;
doublereal d__2;
integer i__;
doublereal value;

void init_vars() {
    const size_t data_size = 1 << 24; // ~8MB of data (2^24 doubles)
    work = (doublereal*)aligned_alloc(32, data_size * sizeof(doublereal));
    if (!work) exit(1);

    for (size_t i = 0; i < data_size; ++i) {
        work[i] = sin(i) * 100.0;
    }

    i__1 = (integer)(data_size - 1);
    value = -50.0;
    d__1 = 0.0;
    d__2 = 0.0;
    i__ = 0;
}