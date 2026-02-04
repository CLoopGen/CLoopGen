#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef double doublereal;

integer i__1;
integer *i__;
doublereal *d__;
doublereal *delta;
doublereal tau;
integer j;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64M doubles = ~512MB total for arrays
    d__ = (doublereal*)calloc(data_size, sizeof(doublereal));
    delta = (doublereal*)calloc(data_size, sizeof(doublereal));
    i__ = (integer*)malloc(sizeof(integer));
    *i__ = 1;
    i__1 = (integer)(data_size * 0.5); // ensure within bounds
    tau = 1.5;
    j = 0;
}

void loop();