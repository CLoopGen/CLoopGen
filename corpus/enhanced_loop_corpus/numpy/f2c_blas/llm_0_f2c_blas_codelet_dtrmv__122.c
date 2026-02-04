#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

typedef int logical;

extern integer *n;
extern doublereal *a;
extern doublereal *x;
extern integer a_dim1;
extern integer i__1;
extern integer i__;
extern integer j;
extern doublereal temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = *n; j >= 1; --j) {
        if (x[j] != 0.) {
            temp = x[j];
            i__1 = j + 1;
            for (i__ = i__1; i__ <= *n; ++i__) {
                x[i__] += temp * a[i__ + j * a_dim1];
            }
            if (nounit) {
                x[j] *= a[j + j * a_dim1];
            }
        }
    }
}
