#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *m;
extern integer *k;
extern real *alpha;
extern real *a;
extern real *b;
extern real *beta;
extern real *c__;
extern integer a_dim1;
extern integer b_dim1;
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
    integer j2 = j + 1;
    if (*beta == 0.F) {
        i__2 = *m;
        for (i__ = 1; i__ <= i__2; ++i__) {
            c__[i__ + j * c_dim1] = 0.F;
            if (j2 <= i__1) {
                c__[i__ + j2 * c_dim1] = 0.F;
            }
        }
    } else if (*beta != 1.F) {
        i__2 = *m;
        for (i__ = 1; i__ <= i__2; ++i__) {
            c__[i__ + j * c_dim1] *= *beta;
            if (j2 <= i__1) {
                c__[i__ + j2 * c_dim1] *= *beta;
            }
        }
    }
    i__2 = *k;
    for (l = 1; l <= i__2; ++l) {
        real blj = b[l + j * b_dim1];
        real blj2 = (j2 <= i__1) ? b[l + j2 * b_dim1] : 0.F;
        int update1 = (blj != 0.F);
        int update2 = (blj2 != 0.F);
        if (update1 || update2) {
            real temp1 = update1 ? *alpha * blj : 0.F;
            real temp2 = update2 ? *alpha * blj2 : 0.F;
            i__3 = *m;
            for (i__ = 1; i__ <= i__3; ++i__) {
                if (update1) c__[i__ + j * c_dim1] += temp1 * a[i__ + l * a_dim1];
                if (update2) c__[i__ + j2 * c_dim1] += temp2 * a[i__ + l * a_dim1];
            }
        }
    }
}
}
