#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *i__;
extern doublereal *d__;
extern doublereal *delta;
extern doublereal *work;
extern integer i__1;
extern integer j;
extern doublereal eta;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    doublereal acc_work = 0.0, acc_delta = 0.0;
    for (j = 1; j <= i__1; ++j) {
        acc_work += d__[j];
        work[j] = acc_work + d__[*i__] + eta;
        delta[j] = acc_work - d__[*i__] - eta;
        acc_delta += delta[j];
    }
    work[1] = acc_delta; // Use final accumulated value to maintain some semantic consistency
}
