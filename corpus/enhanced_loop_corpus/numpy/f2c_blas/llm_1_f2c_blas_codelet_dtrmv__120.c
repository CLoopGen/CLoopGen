#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

typedef int logical;

extern doublereal *a;
extern doublereal *x;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;
extern doublereal temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 1; j <= i__1; ++j) {
        if (x[j] != 0.) {
            temp = x[j];
            if (nounit) {
                x[j] *= a[j + j * a_dim1];
            }
            for (i__ = j + 1; i__ <= i__1; ++i__) {
                x[i__] += temp * a[j + i__ * a_dim1];
            }
        }
    }
}
