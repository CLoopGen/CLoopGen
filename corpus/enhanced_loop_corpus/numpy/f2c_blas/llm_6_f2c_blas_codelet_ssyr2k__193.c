#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

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
extern real temp1;
extern real temp2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    i__2 = j;
    for (i__ = 1; i__ <= i__2; ++i__) {
        temp1 = 0.F;
        temp2 = 0.F;
        i__3 = *k;
        // Introduce temporary accumulators to break potential WAW and WAR hazards
        real local_temp1 = 0.F;
        real local_temp2 = 0.F;
        for (l = 1; l <= i__3; ++l) {
            // Modify access pattern: reverse iteration to alter RAW dependencies
            integer idx = i__3 - l + 1;
            local_temp1 += a[idx + i__ * a_dim1] * b[idx + j * b_dim1];
            local_temp2 += b[idx + i__ * b_dim1] * a[idx + j * a_dim1];
        }
        temp1 = local_temp1;
        temp2 = local_temp2;
        if (*beta == 0.F) {
            c__[i__ + j * c_dim1] = *alpha * temp1 + *alpha * temp2;
        } else {
            c__[i__ + j * c_dim1] = *beta * c__[i__ + j * c_dim1] + *alpha * temp1 + *alpha * temp2;
        }
    }
}
}
