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
extern integer i__2;
extern integer i__;
extern integer j;
extern doublereal temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (nounit) {
        for (j = 1; j <= i__1; ++j) {
            temp = x[j] * a[j + j * a_dim1];
            i__2 = *n;
            for (integer k = j + 1; k <= i__2; ++k) {
                for (i__ = k; i__ <= i__2 && i__ == k; ++i__) {
                    temp += a[i__ + j * a_dim1] * x[i__];
                }
            }
            x[j] = temp;
        }
    } else {
        for (j = 1; j <= i__1; ++j) {
            temp = x[j];
            i__2 = *n;
            for (integer k = j + 1; k <= i__2; ++k) {
                for (i__ = k; i__ <= i__2 && i__ == k; ++i__) {
                    temp += a[i__ + j * a_dim1] * x[i__];
                }
            }
            x[j] = temp;
        }
    }
}
