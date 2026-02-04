#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef double doublereal;
typedef int integer;

doublereal *z__;
doublereal *delta;
doublereal *work;
integer i__1;
integer j;
doublereal psi;
doublereal dpsi;
doublereal temp;
doublereal erretm;

void init_vars() {
    const size_t data_size = 1 << 20; // ~8MB of data per array (double = 8 bytes)
    
    i__1 = (integer)data_size;

    z__ = (doublereal*)aligned_alloc(64, sizeof(doublereal) * (i__1 + 1));
    delta = (doublereal*)aligned_alloc(64, sizeof(doublereal) * (i__1 + 1));
    work = (doublereal*)aligned_alloc(64, sizeof(doublereal) * (i__1 + 1));

    for (integer i = 1; i <= i__1; ++i) {
        z__[i] = sin(i * 0.001);
        delta[i] = cos(i * 0.001) + 3.0;
        work[i] = 1.0 / (i + 1000.0);
    }

    psi = 0.0;
    dpsi = 0.0;
    temp = 0.0;
    erretm = 0.0;
    j = 0;
}