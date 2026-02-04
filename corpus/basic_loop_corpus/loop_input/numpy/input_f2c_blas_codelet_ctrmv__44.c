#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <time.h>
#include <math.h>

typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

typedef int integer;
typedef int logical;

singlecomplex *a;
singlecomplex *x;
integer a_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__4;
integer i__5;
singlecomplex q__1;
singlecomplex q__2;
integer i__;
integer j;
singlecomplex temp;
logical nounit;

void init_vars() {
    const int n = 8192; 
    a_dim1 = n;
    i__1 = n;
    nounit = 1;

    a = (singlecomplex*)aligned_alloc(32, sizeof(singlecomplex) * n * n);
    x = (singlecomplex*)aligned_alloc(32, sizeof(singlecomplex) * (n + 1));

    if (!a || !x) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    uint64_t seed = 12345;
    for (int idx = 0; idx < n * n; ++idx) {
        a[idx].r = (real)(sin((double)(seed % 100)) * 0.1f);
        a[idx].i = (real)(cos((double)(seed % 100)) * 0.1f);
        seed = seed * 1103515245 + 12345;
    }

    for (int idx = 0; idx <= n; ++idx) {
        x[idx].r = (real)((seed % 100) < 10 ? 1.0f : 0.0f);
        x[idx].i = 0.0f;
        seed = seed * 1103515245 + 12345;
    }

    i__ = 0;
    j = 0;
    temp.r = 0.0f; temp.i = 0.0f;
    q__1.r = 0.0f; q__1.i = 0.0f;
    q__2.r = 0.0f; q__2.i = 0.0f;
}