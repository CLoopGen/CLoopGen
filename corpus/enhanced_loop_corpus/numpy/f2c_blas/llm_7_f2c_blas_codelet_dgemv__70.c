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
    doublereal temp_array[256]; // Assuming maximum size based on problem context
    for (j = 1; j <= i__1; ++j) {
        temp_array[j] = 0.;
        i__2 = *m;
        for (i__ = 1; i__ <= i__2; ++i__) {
            temp_array[j] += a[i__ + j * a_dim1] * x[i__];
        }
    }
    for (j = 1; j <= i__1; ++j) {
        y[jy] += *alpha * temp_array[j];
        jy += *incy;
    }
}
