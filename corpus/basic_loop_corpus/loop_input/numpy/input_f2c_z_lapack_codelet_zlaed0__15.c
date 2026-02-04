#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef double doublereal;
typedef int integer;

doublereal *d__ = NULL;
doublereal *e = NULL;
integer *iwork = NULL;
integer i__1;
doublereal d__1;
integer i__;
integer smm1;
integer submat;

void init_vars() {
    const size_t array_size = 134217728; // ~128MB of data (64M doubles * 2 arrays + integers)
    
    d__ = (doublereal*)aligned_alloc(32, array_size * sizeof(doublereal));
    e = (doublereal*)aligned_alloc(32, array_size * sizeof(doublereal));
    iwork = (integer*)aligned_alloc(32, array_size * sizeof(integer));
    
    for (size_t i = 0; i < array_size; ++i) {
        d__[i] = (doublereal)(rand() % 1000) / 10.0;
        e[i] = (doublereal)(rand() % 1000) / 10.0;
        iwork[i] = (integer)(rand() % (array_size/2)) + 1;
    }
    
    i__1 = (integer)(array_size * 0.75);
    d__1 = 0.0;
    i__ = 0;
    smm1 = 0;
    submat = 0;
}