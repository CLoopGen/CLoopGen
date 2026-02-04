#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef int integer;
typedef double doublereal;

integer *i0;
doublereal *z__;
doublereal *tau;
doublereal *dmin__;
integer i__1;
doublereal d__1;
doublereal d__;
integer j4;
doublereal emin;
doublereal temp;

#define ARRAY_SIZE (65536 * 4)

static integer static_i0;
static doublereal static_z[ARRAY_SIZE];
static doublereal static_tau;
static doublereal static_dmin;
static doublereal static_d_val;

void init_vars() {
    i0 = &static_i0;
    z__ = static_z;
    tau = &static_tau;
    dmin__ = &static_dmin;
    d__ = static_d_val;
    
    static_i0 = 2;
    i__1 = ARRAY_SIZE - 2;
    
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        z__[i] = 1.0 + i * 0.001;
    }
    
    static_tau = 0.1;
    static_dmin = 1e30;
    static_d_val = 1.0;
    d__1 = 1.0;
    emin = 1e30;
    temp = 0.0;
}