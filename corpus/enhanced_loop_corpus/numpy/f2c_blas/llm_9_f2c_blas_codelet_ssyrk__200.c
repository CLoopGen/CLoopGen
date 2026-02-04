#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *n;
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
    i__2 = (j + 1 <= i__1) ? j + 1 : j;
    for (integer jj = j; jj <= i__2; ++jj) {
        if (*beta == 0.F) {
            i__3 = *n;
            for (i__ = jj; i__ <= i__3; ++i__) {
                c__[i__ + jj * c_dim1] = 0.F;
            }
        } else if (*beta != 1.F) {
            i__3 = *n;
            for (i__ = jj; i__ <= i__3; ++i__) {
                c__[i__ + jj * c_dim1] = *beta * c__[i__ + jj * c_dim1];
            }
        }
        i__3 = *k;
        for (l = 1; l <= i__3; ++l) {
            real ajl = a[jj + l * a_dim1];
            if (ajl != 0.F) {
                temp = *alpha * ajl;
                for (i__ = jj; i__ <= *n; ++i__) {
                    c__[i__ + jj * c_dim1] += temp * a[i__ + l * a_dim1];
                }
            }
        }
    }
}
}
