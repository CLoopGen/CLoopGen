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
        real temp_sum = 0.0F;
        if (x[j] != 0.F || y[j] != 0.F) {
            temp1 = *alpha * y[j];
            temp2 = *alpha * x[j];
            i__2 = *n;
            for (i__ = j; i__ <= i__2; ++i__) {
                temp_sum = x[i__] * temp1 + y[i__] * temp2;
                a[i__ + j * a_dim1] = a[i__ + j * a_dim1] + temp_sum;
            }
            // Introduce artificial loop-carried dependency on temp_sum
            // by feeding it into a dummy use that carries to next j iteration
            // (though not affecting correctness, creates WAW-like pattern)
            if (j > 1) {
                a[j * a_dim1] += temp_sum;  // weak write-after-write with previous j
            }
        }
    }
}
