#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

typedef double doublereal;

typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;

typedef int integer;

doublecomplex *beta;
doublecomplex *a;
integer a_dim1;
integer i__1;
integer i__2;
integer i__;

static doublecomplex beta_storage = {3.14, 2.71};
static size_t a_size;

void init_vars() {
    // Estimate data size for ~0.01 sec runtime: assume simple loop overhead and target ~1M iterations
    // Modern CPU can do this loop in few ns per iteration -> aim for ~10M elements
    i__1 = 3200;  // Controls the loop count: i from 1 to i__1
    a_dim1 = 3200;
    
    a_size = (a_dim1 + 1) * (i__1 + 1);  // account for 1-based indexing up to i__1,i__1
    a = (doublecomplex*)calloc(a_size, sizeof(doublecomplex));
    if (!a) {
        exit(1);
    }
    
    beta = &beta_storage;
}