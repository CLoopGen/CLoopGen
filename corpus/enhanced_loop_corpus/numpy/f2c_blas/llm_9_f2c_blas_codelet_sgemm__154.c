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
    for (i__ = 1; i__ <= *m; ++i__) {
        if (*beta == 0.F) {
            c__[i__ + j * c_dim1] = 0.F;
            if (j + 1 <= i__1) {
                c__[i__ + (j+1) * c_dim1] = 0.F;
            }
        } else if (*beta != 1.F) {
            c__[i__ + j * c_dim1] *= *beta;
            if (j + 1 <= i__1) {
                c__[i__ + (j+1) * c_dim1] *= *beta;
            }
        }
    }
    for (l = 1; l <= *k; ++l) {
        real beta_temp1 = b[j + l * b_dim1];
        real beta_temp2 = (j + 1 <= i__1) ? b[j + 1 + l * b_dim1] : 0.F;
        int valid2 = (j + 1 <= i__1);
        temp = *alpha * beta_temp1;
        real temp2 = *alpha * beta_temp2;
        for (i__ = 1; i__ <= *m; ++i__) {
            c__[i__ + j * c_dim1] += temp * a[i__ + l * a_dim1];
            if (valid2) {
                c__[i__ + (j+1) * c_dim1] += temp2 * a[i__ + l * a_dim1];
            }
        }
    }
}
}
