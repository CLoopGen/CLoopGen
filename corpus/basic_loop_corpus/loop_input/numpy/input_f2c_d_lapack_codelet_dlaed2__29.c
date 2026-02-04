#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;

integer *coltyp;
integer i__1;
integer i__;
integer n1p1;

void init_vars() {
    const size_t data_size = 134217728; // 128 MB of data to target ~0.01 sec runtime
    coltyp = (integer*)aligned_alloc(_Alignof(integer), data_size * sizeof(integer));
    if (!coltyp) {
        exit(1);
    }

    n1p1 = 0;
    i__1 = data_size - 1;
}

void loop();