#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

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
doublereal d__1;
integer i__;
doublereal sum;
doublereal absa;
doublereal scale;

void init_vars() {
    const integer data_size_mb = 64;
    const integer total_elements = (data_size_mb * (1 << 20)) / sizeof(doublecomplex);
    
    a = (doublecomplex*)aligned_alloc(32, total_elements * sizeof(doublecomplex));
    
    if (!a) exit(1);
    
    for (integer i = 0; i < total_elements; ++i) {
        a[i].r = sin(i * 0.01);
        a[i].i = cos(i * 0.01);
    }
    
    a_dim1 = total_elements > 10000 ? 10000 : total_elements;
    i__1 = total_elements / a_dim1;
    if (i__1 == 0) i__1 = 1;
    else if (i__1 > a_dim1) i__1 = a_dim1;
    
    sum = 1.0;
    scale = 1e-8;
    absa = 0.0;
    d__1 = 0.0;
    i__ = 0;
    i__2 = 0;
}