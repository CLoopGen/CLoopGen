#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef float real;
typedef int integer;

typedef struct {
    real r;
    real i;
} singlecomplex;

singlecomplex *a;
integer a_dim1;
integer i__1;
integer i__2;
integer i__;

void init_vars() {
    const size_t data_size_mb = 64;
    const size_t total_elements = (data_size_mb * 1024 * 1024) / sizeof(singlecomplex);

    a = (singlecomplex*)calloc(total_elements, sizeof(singlecomplex));
    if (!a) {
        exit(1);
    }

    a_dim1 = 1;
    i__1 = (integer)(total_elements - 2);
    i__ = 0;
    i__2 = 0;
}