#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

typedef int integer;
typedef double doublereal;

typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;

integer *n;
doublecomplex *b;
doublereal *rwork;
integer b_dim1;
integer i__1;
integer i__2;
integer i__3;
integer j;
integer jcol;
integer jrow;

static doublecomplex *b_storage = NULL;
static doublereal *rwork_storage = NULL;

void init_vars() {
    const integer data_size_mb = 64;
    const integer total_elements = (data_size_mb * (1 << 20)) / sizeof(doublecomplex);
    
    n = (integer*)malloc(sizeof(integer));
    *n = (integer)sqrt(total_elements);
    if (*n < 1) *n = 1;
    
    b_dim1 = *n;
    i__1 = *n;
    j = 0;
    jcol = 0;
    jrow = 0;
    
    size_t b_size = (size_t)(*n + 1) * (size_t)(*n + 1);
    b_storage = (doublecomplex*)calloc(b_size, sizeof(doublecomplex));
    b = b_storage;
    
    size_t rwork_size = (size_t)(*n) * (size_t)(*n) + 10;
    rwork_storage = (doublereal*)calloc(rwork_size, sizeof(doublereal));
    rwork = rwork_storage;
    
    for (size_t i = 0; i < b_size; ++i) {
        b[i].r = (doublereal)(i % 1000) + 0.1;
        b[i].i = (doublereal)(i % 500) + 0.2;
    }
    
    memset(rwork, 0, rwork_size * sizeof(doublereal));
}