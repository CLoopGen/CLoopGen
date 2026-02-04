#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double doublereal;
typedef int integer;

doublereal *work;
integer i__1;
doublereal d__1;
doublereal d__2;
integer i__;
doublereal value;

void init_vars() {
    i__1 = 16777216;  // 16 million elements ~128 MB of data (assuming double is 8 bytes)
    work = (doublereal *)calloc(i__1 + 1, sizeof(doublereal));
    if (!work) {
        exit(1);
    }
    
    for (integer j = 1; j <= i__1; ++j) {
        work[j] = (doublereal)(rand() % 1000) / 10.0;
    }
    
    value = 50.0;
    d__1 = 0.0;
    d__2 = 0.0;
    i__ = 0;
}