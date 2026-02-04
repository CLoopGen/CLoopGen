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
singlecomplex *t;
singlecomplex *work;
integer t_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__;

void init_vars() {
    const integer data_size = 65536; 

    n = (integer*)malloc(sizeof(integer));
    *n = (integer)(data_size / 4);

    t_dim1 = data_size / 8;
    i__1 = data_size / 16;

    t = (singlecomplex*)calloc((i__1 + *n) + (i__1 * t_dim1) + 1, sizeof(singlecomplex));
    work = (singlecomplex*)calloc((i__1 + *n) + 1, sizeof(singlecomplex));

    for (integer i = 0; i < (i__1 + *n); ++i) {
        work[i].r = 0.0f;
        work[i].i = 0.0f;
    }

    for (integer i = 0; i <= i__1 * t_dim1 + i__1; ++i) {
        t[i].r = (real)(i & 0xFF);
        t[i].i = (real)((i + 1) & 0xFF);
    }
}