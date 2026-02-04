#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *n;
extern doublereal *z__;
extern doublereal *delta;
extern doublereal *work;
extern integer i__1;
extern integer j;
extern doublereal phi;
extern doublereal dphi;
extern doublereal temp;
extern doublereal erretm;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = *n; j >= i__1 + (*n - i__1) / 2; --j) { // Reduced trip count: iterate only over upper half
    temp = z__[j] / work[j]; // Simplified arithmetic: removed multiplication with delta[j]
    phi += z__[j] * temp;
    dphi += temp;
    erretm += phi;
}
}
