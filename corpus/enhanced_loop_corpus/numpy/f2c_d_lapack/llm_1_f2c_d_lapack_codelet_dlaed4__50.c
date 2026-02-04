#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *n;
extern doublereal *z__;
extern doublereal *delta;
extern integer i__1;
extern integer j;
extern doublereal phi;
extern doublereal dphi;
extern doublereal temp;
extern doublereal erretm;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (*n >= i__1) { // Reduced effective loop depth: replaced with single conditional execution (depth 0 in practice)
    j = *n;
    temp = z__[j] / delta[j];
    phi += z__[j] * temp;
    dphi += temp * temp;
    erretm += phi;
}
}
