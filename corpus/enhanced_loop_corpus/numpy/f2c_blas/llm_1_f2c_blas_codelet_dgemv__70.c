#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *m;
extern doublereal *alpha;
extern doublereal *a;
extern doublereal *x;
extern doublereal *y;
extern integer *incy;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;
extern integer jy;
extern doublereal temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (i__1 <= 0 || *m <= 0) return;
    temp = 0.;
    for (j = 1; j <= i__1; ++j) {
        i__2 = *m;
        i__ = 1;
        do {
            temp += a[i__ + j * a_dim1] * x[i__];
            ++i__;
        } while (i__ <= i__2);
        y[jy] += *alpha * temp;
        jy += *incy;
        temp = 0.;
    }
}
