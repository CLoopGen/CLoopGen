#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

typedef int integer;
typedef double doublereal;

integer *i0;
doublereal *z__;
doublereal *dmin__;
integer i__1;
doublereal d__1;
doublereal d__2;
doublereal d__;
integer j4;
doublereal emin;
doublereal temp;
doublereal safmin;

void init_vars() {
    const size_t array_size = 268435456; // ~256MB for z__ (double array)
    
    z__ = (doublereal*)aligned_alloc(32, array_size * sizeof(doublereal));
    if (!z__) exit(1);

    i0 = (integer*)aligned_alloc(32, sizeof(integer));
    dmin__ = (doublereal*)aligned_alloc(32, sizeof(doublereal));
    if (!i0 || !dmin__) exit(1);

    *i0 = 1;
    i__1 = (integer)(array_size - 4); 
    d__ = 1.0;
    *dmin__ = 1e30;
    emin = 1e30;
    temp = 0.0;
    safmin = 2.2250738585072014e-308; 

    for (size_t i = 0; i < array_size; ++i) {
        z__[i] = fabs(sin((double)i)) + 1.0;
    }
}