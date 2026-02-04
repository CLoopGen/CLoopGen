#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double doublereal;
typedef int integer;

doublereal *e;
integer i__1;
doublereal d__1;
integer i__;
integer l;

void init_vars() {
    const size_t data_size = 1 << 20; // 1MB of data: 2^20 bytes / sizeof(double) = 262144 elements
    e = (doublereal *)aligned_alloc(32, data_size);
    if (!e) {
        exit(1);
    }

    for (size_t idx = 0; idx < data_size / sizeof(doublereal); ++idx) {
        e[idx] = (doublereal)(idx + 1);
    }

    l = 0;
    i__1 = (integer)(data_size / sizeof(doublereal) - 1);
}