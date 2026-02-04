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
    // Variant 1: Strided memory access with stride of 2
    // Accesses every second element in reverse order to modify memory access pattern
    for (j = i__1; j >= 1; j -= 2) {
        work[j] = d__[j] + d__[*n] + temp1;
        delta[j] = d__[j] - d__[*n] - temp1;
        if (j == 1) break;
        work[j-1] = d__[j-1] + d__[*n] + temp1;
        delta[j-1] = d__[j-1] - d__[*n] - temp1;
    }
}
