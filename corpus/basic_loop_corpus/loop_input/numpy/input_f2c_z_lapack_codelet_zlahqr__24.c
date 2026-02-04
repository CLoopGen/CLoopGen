#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef double doublereal;

typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;

integer *ilo;
doublecomplex *h__;
integer h_dim1;
integer i__1;
integer i__2;
integer j;

void init_vars() {
    const size_t data_size = 16777216; // ~128 MB for doublecomplex array
    h_dim1 = 65536;
    ilo = (integer*)malloc(sizeof(integer));
    *ilo = 1;
    i__1 = (data_size / h_dim1) - 4;
    if (i__1 < *ilo) i__1 = *ilo;

    h__ = (doublecomplex*)calloc(data_size, sizeof(doublecomplex));
}

// Do not include main(), headers, explanations or comments below this line