#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;

integer *coltyp;
integer i__1;
integer i__;

void init_vars() {
    size_t data_size = 134217728; // ~128MB to target ~0.01s runtime
    coltyp = (integer*)calloc(data_size, sizeof(integer));
    if (!coltyp) {
        exit(1);
    }
    i__1 = (integer)(data_size - 1); // ensures coltyp[i__] access is in bounds for i__ from 2 to i__1
    i__ = 0;
}