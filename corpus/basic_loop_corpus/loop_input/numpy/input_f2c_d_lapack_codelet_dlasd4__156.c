#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double doublereal;
typedef int integer;

doublereal *delta;
doublereal *work;
integer i__1;
integer j;
doublereal eta;

void init_vars() {
    size_t data_size = 1 << 20; // ~16 MB of data (2^20 elements)

    i__1 = (integer)(data_size - 1); // ensure j from 1 to i__1 is valid index
    eta = 1.5;

    delta = (doublereal*)calloc(data_size, sizeof(doublereal));
    work = (doublereal*)calloc(data_size, sizeof(doublereal));

    if (delta == NULL || work == NULL) {
        exit(1);
    }
}