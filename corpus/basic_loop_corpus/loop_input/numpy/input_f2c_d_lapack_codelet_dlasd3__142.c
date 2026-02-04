#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double doublereal;
typedef int integer;

doublereal *u;
doublereal *u2;
integer u_dim1;
integer u2_dim1;
integer i__1;
integer i__;

#define DATA_SIZE (64 << 20) / sizeof(doublereal)

void init_vars() {
    u_dim1 = 0;
    u2_dim1 = 0;
    i__1 = DATA_SIZE - 1;

    u = (doublereal*)calloc(DATA_SIZE, sizeof(doublereal));
    u2 = (doublereal*)calloc(DATA_SIZE, sizeof(doublereal));

    if (!u || !u2) {
        exit(1);
    }
}