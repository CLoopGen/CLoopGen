#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double R;
typedef ptrdiff_t INT;
typedef R E;

R *I0;
R *I1;
INT i;
INT n;
INT is;

static R *arr0;
static R *arr1;

void init_vars() {
    n = 131072; 
    is = 1;
    INT num_elements = n;
    arr0 = (R*)aligned_alloc(32, num_elements * sizeof(R));
    arr1 = (R*)aligned_alloc(32, num_elements * sizeof(R));
    if (!arr0 || !arr1) {
        exit(1);
    }
    for (INT j = 0; j < num_elements; ++j) {
        arr0[j] = (R)0.0;
        arr1[j] = (R)0.0;
    }
    I0 = arr0;
    I1 = arr1;
}