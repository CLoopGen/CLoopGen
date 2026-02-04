#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef float real;
typedef int integer;
typedef double doublereal;

real *d__ = NULL;
real *e = NULL;
integer *iwork = NULL;
integer i__1;
real r__1;
integer i__;
integer smm1;
integer submat;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~256 MB of total data (adjustable)

    d__ = (real *)aligned_alloc(32, data_size * sizeof(real));
    e = (real *)aligned_alloc(32, data_size * sizeof(real));
    iwork = (integer *)aligned_alloc(32, data_size * sizeof(integer));

    for (size_t i = 0; i < data_size; ++i) {
        d__[i] = (real)(rand() % 100) / 10.0f;
        e[i] = (real)(rand() % 100) / 10.0f;
        iwork[i] = rand() % (data_size - 2); 
    }

    i__1 = (integer)(data_size * 0.8); 

    r__1 = 0.0f;
    i__ = 0;
    smm1 = 0;
    submat = 0;
}