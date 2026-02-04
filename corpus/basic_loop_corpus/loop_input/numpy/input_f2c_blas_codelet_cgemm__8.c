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

integer *m;
singlecomplex *beta;
singlecomplex *c__;
integer c_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__4;
singlecomplex q__1;
integer i__;
integer j;

void init_vars() {
    i__1 = 500;        
    c_dim1 = 1000;      
    m = (integer*)malloc(sizeof(integer));
    *m = 1000;          

    beta = (singlecomplex*)malloc(sizeof(singlecomplex));
    beta->r = 1.5f;
    beta->i = 0.8f;

    size_t total_size = (size_t)(*m) * c_dim1;
    c__ = (singlecomplex*)calloc(total_size, sizeof(singlecomplex));
    if (!c__) {
        exit(1);
    }

    for (size_t idx = 0; idx < total_size; ++idx) {
        c__[idx].r = (real)(idx % 100) + 0.1f;
        c__[idx].i = (real)(idx % 75) + 0.2f;
    }
}