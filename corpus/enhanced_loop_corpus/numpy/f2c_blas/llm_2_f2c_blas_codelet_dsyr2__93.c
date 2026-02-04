#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *n;
extern doublereal *alpha;
extern doublereal *x;
extern doublereal *y;
extern doublereal *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;
extern doublereal temp1;
extern doublereal temp2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    if (x[j] != 0. || y[j] != 0.) {
        temp1 = *alpha * y[j];
        temp2 = *alpha * x[j];
        i__2 = *n;
        for (i__ = j; i__ <= i__2; i__ += 2) {  // Strided access: increment by 2
            a[i__ + j * a_dim1] = a[i__ + j * a_dim1] + x[i__] * temp1 + y[i__] * temp2;
            if (i__ + 1 <= i__2) {  // Handle boundary condition
                a[i__ + 1 + j * a_dim1] = a[i__ + 1 + j * a_dim1] + x[i__ + 1] * temp1 + y[i__ + 1] * temp2;
            }
        }
    }
}
}
