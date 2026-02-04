#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double doublereal;
typedef int integer;

doublereal *z__;
doublereal *delta;
integer i__1;
integer j;
doublereal psi;
doublereal dpsi;
doublereal temp;
doublereal erretm;

void init_vars() {
    const size_t data_size = 20000000; // ~160 MB of total array data
    
    z__ = (doublereal*)calloc(data_size, sizeof(doublereal));
    delta = (doublereal*)calloc(data_size, sizeof(doublereal));
    
    if (z__ == NULL || delta == NULL) {
        exit(1);
    }
    
    for (size_t i = 1; i < data_size; ++i) {
        z__[i] = (doublereal)(i + 1) * 0.5;
        delta[i] = (doublereal)(i + 1) * 2.0;
    }
    
    i__1 = (integer)(data_size - 1);
    j = 0;
    psi = 0.0;
    dpsi = 0.0;
    temp = 0.0;
    erretm = 0.0;
}