#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double doublereal;

typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;

typedef int integer;

doublecomplex *a;
integer a_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__;
integer j;
integer kk;

void init_vars() {
    a_dim1 = 1024;
    kk = 512;
    i__1 = a_dim1;
    
    size_t total_size = (size_t)(a_dim1 + 1) * (size_t)(i__1 + 1);
    a = (doublecomplex*)calloc(total_size, sizeof(doublecomplex));
    
    if (!a) {
        exit(1);
    }
}
