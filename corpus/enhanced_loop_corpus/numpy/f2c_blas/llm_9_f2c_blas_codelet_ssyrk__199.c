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
for (j = 1; j <= i__1; j += 2) {
    i__2 = (j < i__1) ? j + 1 : j;
    for (integer jj = j; jj <= i__2; ++jj) {
        if (*beta == 0.F) {
            i__3 = jj;
            for (i__ = 1; i__ <= i__3; ++i__) {
                c__[i__ + jj * c_dim1] = 0.F;
            }
        } else if (*beta != 1.F) {
            i__3 = jj;
            for (i__ = 1; i__ <= i__3; ++i__) {
                c__[i__ + jj * c_dim1] = *beta * c__[i__ + jj * c_dim1];
            }
        }
        i__3 = *k;
        for (l = 1; l <= i__3; ++l) {
            real a_val = a[jj + l * a_dim1];
            if (a_val != 0.F) {
                temp = *alpha * a_val;
                i__1 = jj;
                for (i__ = 1; i__ <= i__1; ++i__) {
                    c__[i__ + jj * c_dim1] += temp * a[i__ + l * a_dim1];
                }
            }
        }
    }
}
}
