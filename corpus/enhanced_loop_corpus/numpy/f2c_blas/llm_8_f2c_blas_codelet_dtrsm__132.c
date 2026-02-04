#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

typedef int logical;

extern integer *m;
extern doublereal *alpha;
extern doublereal *a;
extern doublereal *b;
extern integer a_dim1;
extern integer b_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;
extern integer k;
extern doublereal temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
doublereal *temp_arr = (doublereal*)alloca(*m * sizeof(doublereal));
for (j = 1; j <= i__1; ++j) {
    for (i__ = *m; i__ >= 1; --i__) {
        temp_arr[i__ - 1] = *alpha * b[i__ + j * b_dim1];
        i__2 = *m;
        for (k = i__ + 1; k <= i__2; ++k) {
            temp_arr[i__ - 1] -= a[k + i__ * a_dim1] * b[k + j * b_dim1];
        }
        if (nounit) {
            temp_arr[i__ - 1] /= a[i__ + i__ * a_dim1];
        }
    }
    for (i__ = *m; i__ >= 1; --i__) {
        b[i__ + j * b_dim1] = temp_arr[i__ - 1];
    }
}
}
