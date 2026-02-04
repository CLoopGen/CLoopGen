#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

typedef int integer;
typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

integer *n;
singlecomplex *z__;
real *rwork;
integer z_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__4;
integer i__;
integer j;

void init_vars() {
    const integer data_size_mb = 64;
    const integer total_elements = (data_size_mb * (1 << 20)) / sizeof(real);
    
    n = (integer*)malloc(sizeof(integer));
    *n = (integer)sqrt(total_elements);
    if (*n < 1) *n = 1;

    z_dim1 = *n;
    i__1 = *n;

    size_t z_size = (size_t)(*n + 1) * (size_t)(*n + 1);
    z__ = (singlecomplex*)calloc(z_size, sizeof(singlecomplex));

    size_t rwork_size = (size_t)(*n) * (size_t)(*n);
    rwork = (real*)malloc(rwork_size * sizeof(real));

    for (size_t idx = 0; idx < rwork_size; ++idx) {
        rwork[idx] = (real)(rand() % 1000) / 10.0f;
    }

    i__ = 0;
    j = 0;
    i__2 = 0;
    i__3 = 0;
    i__4 = 0;
}