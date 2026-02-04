#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

typedef int integer;

singlecomplex *y;
integer i__1;
integer i__2;
integer i__;

void init_vars() {
    const size_t data_size = 1 << 20; // 1M elements, ~8MB for complex floats
    y = (singlecomplex*)aligned_alloc(32, data_size * sizeof(singlecomplex));
    if (!y) {
        exit(1);
    }
    i__1 = data_size - 1;
}
// End of file