#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;

integer i__1;
integer i__;
integer *coltyp;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // ~64MB of data for ~0.01 sec runtime estimate
    coltyp = (integer*)calloc(data_size, sizeof(integer));
    if (!coltyp) {
        exit(1);
    }
    i__1 = (integer)(data_size - 1);
    i__ = 0;
}