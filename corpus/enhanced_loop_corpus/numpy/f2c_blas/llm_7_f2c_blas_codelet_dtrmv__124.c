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
extern integer i__;
extern integer j;
extern doublereal temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    doublereal temp_local;
    for (j = *n; j >= 1; --j) {
        temp_local = x[j];
        if (nounit) {
            temp_local *= a[j + j * a_dim1];
        }
        for (i__ = 1; i__ <= j - 1; ++i__) {
            temp_local += a[i__ + j * a_dim1] * x[i__];
        }
        x[j] = temp_local;
    }
}
