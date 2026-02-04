#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

typedef int logical;

extern integer *n;
extern real *a;
extern real *x;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;
extern real temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 1; j <= i__1; ++j) {
        temp = x[j];
        if (nounit) {
            temp *= a[j + j * a_dim1];
        }
        i__2 = *n;
        for (i__ = j + 1; i__ <= i__2; ++i__) {
            x[j] += a[i__ + j * a_dim1] * x[i__];
        }
        x[j] = temp;
    }
}
