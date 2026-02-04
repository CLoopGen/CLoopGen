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
integer i__;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64M elements, adjust for ~0.01s runtime
    a_dim1 = 1000; 
    i__1 = (data_size / sizeof(doublecomplex)) - a_dim1 - 1; 

    if (i__1 < 2) {
        i__1 = 2;
    }

    a = (doublecomplex*)calloc(data_size, 1);
    if (!a) {
        exit(1);
    }
}