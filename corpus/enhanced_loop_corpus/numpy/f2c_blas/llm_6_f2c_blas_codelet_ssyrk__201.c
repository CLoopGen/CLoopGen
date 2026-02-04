#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *k;
extern real *alpha;
extern real *a;
extern real *beta;
extern real *c__;
extern integer a_dim1;
extern integer c_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__;
extern integer j;
extern integer l;
extern real temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 1; j <= i__1; ++j) {
        i__2 = j;
        for (i__ = 1; i__ <= i__2; ++i__) {
            temp = 0.F;
            i__3 = *k;
            real sum1 = 0.F, sum2 = 0.F;
            integer l = 1;
            // Unroll loop by 2 to modify data dependency pattern (introduce partial accumulation)
            for (; l <= i__3 - 1; l += 2) {
                sum1 += a[l + i__ * a_dim1] * a[l + j * a_dim1];
                sum2 += a[l+1 + i__ * a_dim1] * a[l+1 + j * a_dim1];
            }
            temp = sum1 + sum2;
            // Handle leftover iteration
            if (l <= i__3) {
                temp += a[l + i__ * a_dim1] * a[l + j * a_dim1];
            }
            if (*beta == 0.F) {
                c__[i__ + j * c_dim1] = *alpha * temp;
            } else {
                c__[i__ + j * c_dim1] = *alpha * temp + *beta * c__[i__ + j * c_dim1];
            }
        }
    }
}
