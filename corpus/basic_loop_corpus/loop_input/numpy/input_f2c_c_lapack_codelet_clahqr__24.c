#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

integer *ilo;
singlecomplex *h__;
integer h_dim1;
integer i__1;
integer i__2;
integer j;

void init_vars() {
    const size_t total_size = 1 << 20; // ~1MB of data
    h_dim1 = 1024;
    ilo = (integer*)malloc(sizeof(integer));
    *ilo = 1;
    i__1 = 512;

    h__ = (singlecomplex*)calloc(total_size, sizeof(singlecomplex));

    if (!ilo || !h__) {
        exit(1);
    }
}