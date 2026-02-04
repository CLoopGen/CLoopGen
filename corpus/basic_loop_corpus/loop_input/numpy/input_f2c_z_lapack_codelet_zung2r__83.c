#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef int integer;
typedef double doublereal;

typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;

integer *m;
integer *k;
doublecomplex *a;
integer a_dim1;
integer i__1;
integer i__2;
integer i__3;
integer j;
integer l;

void init_vars() {
    const size_t target_bytes = 64 * 1024 * 1024; // Aim for ~64 MB of data
    const size_t estimated_dim = (size_t)sqrt(target_bytes / sizeof(doublecomplex));
    
    a_dim1 = (integer)estimated_dim;
    i__1 = a_dim1;
    m = (integer*)malloc(sizeof(integer));
    k = (integer*)malloc(sizeof(integer));
    *m = a_dim1;
    *k = 1;

    a = (doublecomplex*)calloc((size_t)(a_dim1 + 1) * (size_t)(a_dim1 + 1), sizeof(doublecomplex));
}