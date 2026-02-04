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
singlecomplex *a;
real *rwork;
integer a_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__;
integer j;

void init_vars() {
    const integer size_m = 4096;  
    const integer size_n = 4096;  

    m = (integer*)malloc(sizeof(integer));
    *m = size_m;
    a_dim1 = size_m;
    i__1 = size_n;

    a = (singlecomplex*)calloc((size_m * size_n + 1), sizeof(singlecomplex));
    rwork = (real*)calloc(size_m * size_n, sizeof(real));

    if (!a || !rwork || !m) {
        exit(1);
    }
}

// DO NOT include main, headers, explanations or comments below.