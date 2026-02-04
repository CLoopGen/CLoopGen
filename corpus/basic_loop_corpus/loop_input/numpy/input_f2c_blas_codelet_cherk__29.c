#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>

typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

typedef int integer;

singlecomplex *c__ = NULL;
integer c_dim1 = 0;
integer i__1 = 0;
integer i__2 = 0;
integer i__3 = 0;
integer i__ = 0;
integer j = 0;

void init_vars() {
    i__1 = 500;
    c_dim1 = i__1 + 1;
    
    size_t total_size = (size_t)(c_dim1 + 1) * (c_dim1 + 1);
    c__ = (singlecomplex*)calloc(total_size, sizeof(singlecomplex));
    
    if (c__ == NULL) {
        exit(1);
    }
}