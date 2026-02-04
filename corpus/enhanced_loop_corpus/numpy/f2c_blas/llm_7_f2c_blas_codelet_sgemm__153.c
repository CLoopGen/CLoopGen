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
for (j = 1; j <= i__1; ++j) {
    i__2 = *m;
    for (i__ = 1; i__ <= i__2; ++i__) {
        temp = 0.F;
        i__3 = *k;
        real local_temp[4] = {0.F};
        integer unroll_factor = 4;
        integer vectorized_end = i__3 - (i__3 % unroll_factor);
        for (l = 1; l <= vectorized_end; l += unroll_factor) {
            local_temp[0] += a[l   + i__ * a_dim1] * b[l   + j * b_dim1];
            local_temp[1] += a[l+1 + i__ * a_dim1] * b[l+1 + j * b_dim1];
            local_temp[2] += a[l+2 + i__ * a_dim1] * b[l+2 + j * b_dim1];
            local_temp[3] += a[l+3 + i__ * a_dim1] * b[l+3 + j * b_dim1];
        }
        for (; l <= i__3; ++l) {
            temp += a[l + i__ * a_dim1] * b[l + j * b_dim1];
        }
        temp += local_temp[0] + local_temp[1] + local_temp[2] + local_temp[3];
        c__[i__ + j * c_dim1] = (*beta == 0.F) ? 
                                *alpha * temp : 
                                *alpha * temp + *beta * c__[i__ + j * c_dim1];
    }
}
}
