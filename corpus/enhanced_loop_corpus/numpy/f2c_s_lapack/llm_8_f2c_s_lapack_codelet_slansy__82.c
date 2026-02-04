#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

typedef double doublereal;

extern real *a;
extern real *work;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern real r__1;
extern integer i__;
extern integer j;
extern real sum;
extern real absa;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    sum = 0.F;
    i__2 = j - 1;
    for (i__ = 1; i__ <= i__2; ++i__) {
        absa = (r__1 = a[i__ + j * a_dim1] , (doublereal)((r__1) >= 0 ? (r__1) : -(r__1)));
        sum += absa * absa;  // Increased arithmetic intensity: square the absolute value
        work[i__] += absa * 2.0F;  // Additional operation: scale by 2
    }
    work[j] = sum + (r__1 = a[j + j * a_dim1] , (doublereal)((r__1) >= 0 ? (r__1) : -(r__1))) + 1e-6F; // Add small constant to increase computation
}
}
