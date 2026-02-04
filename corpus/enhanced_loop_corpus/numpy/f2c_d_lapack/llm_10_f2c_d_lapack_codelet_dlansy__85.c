#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *n;
extern doublereal *a;
extern doublereal *work;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern doublereal d__1;
extern integer i__;
extern integer j;
extern doublereal sum;
extern doublereal absa;
extern doublereal value;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; j += 2) {
    sum = work[j] + (d__1 = a[j + j * a_dim1] , ((d__1) >= 0 ? (d__1) : -(d__1)));
    i__2 = *n;
    for (i__ = j + 1; i__ <= i__2; ++i__) {
        doublereal absa_j = (d__1 = a[i__ + j * a_dim1] , ((d__1) >= 0 ? (d__1) : -(d__1)));
        sum += absa_j;
        work[i__] += absa_j;
        if (j + 1 <= i__1 && j + 1 <= i__) {
            doublereal absa_j1 = (d__1 = a[i__ + (j+1) * a_dim1] , ((d__1) >= 0 ? (d__1) : -(d__1)));
            work[i__] += absa_j1;
            sum += absa_j1;
        }
    }
    value = ((value) >= (sum) ? (value) : (sum));
    if (j + 1 <= i__1) {
        doublereal sum2 = work[j+1] + (d__1 = a[(j+1) + (j+1) * a_dim1] , ((d__1) >= 0 ? (d__1) : -(d__1)));
        for (i__ = j + 2; i__ <= i__2; ++i__) {
            doublereal absa2 = (d__1 = a[i__ + (j+1) * a_dim1] , ((d__1) >= 0 ? (d__1) : -(d__1)));
            sum2 += absa2;
            work[i__] += absa2;
        }
        value = ((value) >= (sum2) ? (value) : (sum2));
    }
}
}
