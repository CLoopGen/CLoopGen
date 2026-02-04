#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;

integer *coltyp;
integer i__1;
integer i__;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // ~64MB of data for sufficient runtime (~0.01 sec on modern CPU)

    coltyp = (integer*)calloc(data_size, sizeof(integer));
    if (!coltyp) {
        exit(1);
    }

    i__1 = data_size - 1; // ensures coltyp[i__] access is in bounds for i__ from 2 to i__1
}