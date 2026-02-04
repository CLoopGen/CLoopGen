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
for (j = 1; j <= i__1; j += 2) {
    sum = 0.0;
    i__2 = *n;
    for (i__ = 1; i__ <= i__2; ++i__) {
        real temp1 = 0.0, temp2 = 0.0;
        if (j <= i__1 && i__ >= j + 1) {
            temp1 = (r__1 = a[i__ + j * a_dim1], (doublereal)((r__1) >= 0 ? r__1 : -r__1));
            sum += temp1;
            work[i__] += temp1;
        }
        if (j + 1 <= i__1 && i__ >= j + 2) {
            temp2 = (r__1 = a[i__ + (j+1) * a_dim1], (doublereal)((r__1) >= 0 ? r__1 : -r__1));
            sum += temp2;
            work[i__] += temp2;
        }
    }
    if (j <= i__1) {
        sum += work[j] + (r__1 = a[j + j * a_dim1], (doublereal)((r__1) >= 0 ? r__1 : -r__1));
        value = (doublereal)((value) >= (sum) ? (value) : (sum));
    }
    if (j + 1 <= i__1) {
        real sum2 = work[j+1] + (r__1 = a[(j+1) + (j+1) * a_dim1], (doublereal)((r__1) >= 0 ? r__1 : -r__1));
        i__2 = *n;
        for (i__ = j + 2; i__ <= i__2; ++i__) {
            real absa2 = (r__1 = a[i__ + (j+1) * a_dim1], (doublereal)((r__1) >= 0 ? r__1 : -r__1));
            sum2 += absa2;
            work[i__] += absa2;
        }
        value = (doublereal)((value) >= (sum2) ? (value) : (sum2));
    }
}
}
