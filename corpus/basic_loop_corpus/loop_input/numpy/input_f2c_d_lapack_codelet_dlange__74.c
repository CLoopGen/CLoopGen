#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef int integer;
typedef double doublereal;

integer m_storage = 10000;
integer *m = &m_storage;

doublereal *a = NULL;
integer a_dim1 = 10000;

integer i__1 = 10000;
integer i__2;
integer i__;
integer j;
doublereal sum;
doublereal value;
doublereal d__1;

void init_vars() {
    const size_t size = (size_t)m_storage * (size_t)i__1;
    a = (doublereal*)calloc(size, sizeof(doublereal));
    if (!a) {
        exit(1);
    }
    
    for (size_t idx = 0; idx < size; ++idx) {
        a[idx] = sin(idx % 1000) * 100.0;
    }
    
    value = 0.0;
}