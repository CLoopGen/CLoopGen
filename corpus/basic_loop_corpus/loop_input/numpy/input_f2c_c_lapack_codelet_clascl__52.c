#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

typedef int integer;

singlecomplex *a;
integer a_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__4;
singlecomplex q__1;
integer i__;
integer j;
integer k1;
integer k3;
real mul;

void init_vars() {
    const int total_size_mb = 64;
    const int element_size = sizeof(singlecomplex);
    const int desired_elements = (total_size_mb * 1024 * 1024) / element_size;
    
    a_dim1 = (int)sqrt(desired_elements);
    int a_dim2 = (desired_elements + a_dim1 - 1) / a_dim1;
    
    a = (singlecomplex*)calloc(a_dim1 * a_dim2, sizeof(singlecomplex));
    
    if (!a) {
        exit(1);
    }
    
    for (int idx = 0; idx < a_dim1 * a_dim2; ++idx) {
        a[idx].r = (real)(rand() % 100) / 10.0f;
        a[idx].i = (real)(rand() % 100) / 10.0f;
    }
    
    i__1 = a_dim2 - 1;
    k1 = a_dim1 + 1;
    k3 = a_dim1 - 1;
    mul = 1.5f;
}