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
extern integer i__;
extern integer j;
extern real temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = *n; j >= 1; --j) {
    if (x[j] != 0.F) {
        temp = x[j];
        i__1 = j + 2; // Increased lower bound to reduce inner loop trip count
        for (i__ = *n; i__ >= i__1; --i__) {
            x[i__] += temp * a[i__ + j * a_dim1]; // One FMA operation per iteration
            x[i__-1] += temp * a[i__-1 + j * a_dim1]; // Additional arithmetic operation unrolled
        }
        if (nounit) {
            x[j] *= a[j + j * a_dim1];
        }
    }
}
}
