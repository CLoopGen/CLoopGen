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

singlecomplex *a;
integer a_dim1;
integer i__1;
integer i__2;
integer i__;

void init_vars() {
    const size_t data_size_mb = 64;
    const size_t total_elements = (data_size_mb * 1024 * 1024) / sizeof(singlecomplex);
    
    a_dim1 = (integer)(total_elements / 2);
    i__1 = a_dim1 - 1;

    a = (singlecomplex*)calloc(total_elements, sizeof(singlecomplex));
    if (!a) {
        exit(1);
    }
}