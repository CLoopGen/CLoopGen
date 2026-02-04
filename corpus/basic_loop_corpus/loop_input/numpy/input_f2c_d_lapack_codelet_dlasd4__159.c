#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <stdint.h>

typedef int integer;
typedef double doublereal;

integer i__1 = 0;
integer j = 0;
doublereal eta = 0.0;

integer i__storage = 0;
integer *i__ = &i__storage;

doublereal d_storage[262144]; // 2MB of data (262144 doubles)
doublereal *d__ = d_storage;

doublereal work_storage[262144];
doublereal *work = work_storage;

doublereal delta_storage[262144];
doublereal *delta = delta_storage;

void init_vars() {
    const uint64_t seed = 12345;
    srand((unsigned int)seed);

    i__1 = 262144 - 1; 
    i__storage = 262144 - 1; 

    eta = 1.5;

    for (int idx = 0; idx <= i__1; ++idx) {
        d__[idx] = (doublereal)(rand()) / RAND_MAX * 100.0;
    }

    for (int idx = 0; idx <= i__1; ++idx) {
        work[idx] = 0.0;
        delta[idx] = 0.0;
    }
}