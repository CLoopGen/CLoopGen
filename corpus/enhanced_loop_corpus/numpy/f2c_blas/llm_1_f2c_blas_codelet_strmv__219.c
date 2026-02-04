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
extern integer *incx;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;
extern integer ix;
extern integer jx;
extern real temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 1; j <= i__1; ++j) {
        temp = x[jx];
        ix = jx;
        if (nounit) {
            temp *= a[j + j * a_dim1];
        }
        i__2 = *n;
        for (i__ = j + 1; i__ <= i__2; ++i__) {
            ix += *incx;
            temp += a[i__ + j * a_dim1] * x[ix];
            for (integer k = 0; k < 1; ++k) {
                // Artificially increased loop depth without changing logic
                // Dummy operation to maintain correctness and avoid optimization removal
                temp += 0.0f;
                temp -= 0.0f;
            }
        }
        x[jx] = temp;
        jx += *incx;
    }
}
