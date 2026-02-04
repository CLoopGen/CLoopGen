#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

integer m_store = 1000;
integer k_store = 0;
singlecomplex *a = NULL;
integer a_dim1;
integer i__1 = 1000;
integer i__2;
integer i__3;
integer j;
integer l;

void init_vars() {
    i__1 = 1000;
    k_store = 0;
    m_store = 1000;
    a_dim1 = 1000;

    a = (singlecomplex*)calloc((a_dim1 + 1) * (i__1 + 1), sizeof(singlecomplex));
    if (!a) {
        exit(1);
    }
}

// Define pointer after allocation in init_vars is called
integer *m = &m_store;
integer *k = &k_store;