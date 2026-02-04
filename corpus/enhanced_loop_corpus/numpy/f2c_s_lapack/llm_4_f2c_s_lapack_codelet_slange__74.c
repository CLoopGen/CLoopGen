#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

typedef double doublereal;

extern integer *m;
extern real *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern real r__1;
extern integer i__;
extern integer j;
extern real sum;
extern real value;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    sum = 0.F;
    i__2 = *m;
    for (i__ = 1; i__ <= i__2; ++i__) {
        if (a[i__ + j * a_dim1] < 0) continue;
        sum += a[i__ + j * a_dim1];
    }
    value = (doublereal)((value) >= (sum) ? (value) : (sum));
}
