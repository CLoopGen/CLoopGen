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
    size_t data_size = 128 << 20; // 128 MB
    work = (doublereal *)calloc(data_size, sizeof(doublereal));
    if (!work) {
        exit(1);
    }
    i__1 = (integer)(data_size - 1);
}