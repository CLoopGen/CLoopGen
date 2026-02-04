#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef int integer;
typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

integer *m;
singlecomplex *alpha;
singlecomplex *x;
integer *incx;
singlecomplex *y;
integer *incy;
singlecomplex *a;
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
integer ix;
integer jy;
integer kx;
singlecomplex temp;

#define DATA_SIZE_MB 64
#define TOTAL_ELEMENTS ((DATA_SIZE_MB * 1024 * 1024) / sizeof(singlecomplex))

void init_vars() {
    // Allocate and initialize scalar variables
    m = (integer*)malloc(sizeof(integer));
    incx = (integer*)malloc(sizeof(integer));
    incy = (integer*)malloc(sizeof(integer));
    alpha = (singlecomplex*)malloc(sizeof(singlecomplex));
    
    *m = (integer)sqrt(TOTAL_ELEMENTS / 4);
    *incx = 1;
    *incy = 1;
    alpha->r = 1.5f;
    alpha->i = 0.5f;
    
    i__1 = *m;
    a_dim1 = *m;
    
    // Allocate arrays with appropriate sizes to prevent out-of-bounds access
    x = (singlecomplex*)calloc(TOTAL_ELEMENTS, sizeof(singlecomplex));
    y = (singlecomplex*)calloc(TOTAL_ELEMENTS, sizeof(singlecomplex));
    a = (singlecomplex*)calloc((size_t)(*m) * (size_t)a_dim1 + 1, sizeof(singlecomplex));
    
    // Initialize x and y with non-zero values to ensure conditional branch is taken
    for (int idx = 0; idx < *m; ++idx) {
        x[idx].r = (real)(idx + 1) * 0.1f;
        x[idx].i = (real)(idx + 1) * 0.05f;
        y[idx].r = (real)(idx + 1) * 0.08f;
        y[idx].i = (real)(idx + 1) * 0.03f;
    }
    
    // Set up loop indices
    kx = 1;
    jy = 1;
}