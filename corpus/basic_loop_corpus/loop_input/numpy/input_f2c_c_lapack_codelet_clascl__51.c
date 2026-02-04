#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>

typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

typedef int integer;

singlecomplex *a;
integer a_dim1 = 1024;
integer i__1 = 512;
integer i__2;
integer i__3;
integer i__4;
singlecomplex q__1;
integer i__;
integer j;
integer k3 = 1024;
integer k4 = 1024;
real mul = 1.5f;

void init_vars() {
    const size_t total_size = (size_t)(a_dim1 + 1) * (size_t)(i__1 + 1);
    a = (singlecomplex*)aligned_alloc(32, total_size * sizeof(singlecomplex));
    if (!a) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    
    for (size_t idx = 0; idx < total_size; ++idx) {
        a[idx].r = (real)(idx % 100) * 0.5f;
        a[idx].i = (real)(idx % 79) * 0.3f;
    }
}