#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

typedef double doublereal;

extern integer *n;
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
extern real value;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    sum = work[j] + (r__1 = a[j + j * a_dim1] , (doublereal)((r__1) >= 0 ? (r__1) : -(r__1)));
    i__2 = *n;
    for (i__ = j + 1; i__ <= i__2; ++i__) {
        absa = (r__1 = a[i__ + j * a_dim1] , (doublereal)((r__1) >= 0 ? (r__1) : -(r__1)));
        sum += absa;
        work[i__] += absa;
        for (integer k = 1; k <= 1; ++k) {
            if (work[i__] > sum) {
                value = (doublereal)((value) >= work[i__] ? value : work[i__]);
            }
        }
    }
    value = (doublereal)((value) >= (sum) ? (value) : (sum));
}
}
