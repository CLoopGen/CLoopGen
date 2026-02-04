#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;

integer i__1;
integer i__;
integer *coltyp;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // ~64MB to target ~0.01s runtime
    coltyp = (integer*)calloc(data_size, sizeof(integer));
    if (!coltyp) {
        exit(1);
    }
    i__1 = (integer)(data_size - 1); // Ensure no out-of-bounds access
    i__ = 0; // Will be set to 1 at loop start
}