#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *n;
extern doublereal *d__;
extern doublereal *delta;
extern doublereal *work;
extern integer i__1;
extern integer j;
extern doublereal temp1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    doublereal temp_d_n = d__[*n];
    for (j = 1; j <= i__1; ++j) {
        temp1 = d__[j] + temp_d_n;        
        work[j] = temp1;
        delta[j] = temp1 - 2.0 * temp_d_n;
    }
}
