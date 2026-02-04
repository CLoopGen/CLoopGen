#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double doublereal;
typedef int integer;

doublereal *z__ = NULL;
integer i__1 = 0;
integer k = 0;

void init_vars() {
    i__1 = 16777216;  // Size to target ~0.01s runtime: 16M doubles = 128 MB
    z__ = (doublereal*)calloc(i__1 + 1, sizeof(doublereal));
    if (!z__) {
        exit(1);
    }
}