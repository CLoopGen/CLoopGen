#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *n;
extern real *alpha;
extern real *x;
extern real *y;
extern real *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;
extern real temp1;
extern real temp2;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (j = 1; j <= i__1; ++j) {
    if (x[j] != 0.F || y[j] != 0.F) {
        temp1 = *alpha * y[j];
        temp2 = *alpha * x[j];
        i__2 = *n;
        for (i__ = j; i__ <= i__2; ++i__) {
            a[i__ + j * a_dim1] = a[i__ + j * a_dim1] + x[i__] * temp1 + y[i__] * temp2;
        }
    }
}

}
