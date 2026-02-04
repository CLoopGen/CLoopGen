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
for (j = 1; j <= i__1; j += 2) {
    for (i__ = 1; i__ <= j; ++i__) {
        temp1 = 0.F;
        temp2 = 0.F;
        i__3 = *k;
        for (l = 1; l <= i__3; ++l) {
            real a_val_ij = a[l + i__ * a_dim1];
            real b_val_ij = b[l + i__ * b_dim1];
            real a_val_jl = a[l + j * a_dim1];
            real b_val_jl = b[l + j * b_dim1];
            temp1 += a_val_ij * b_val_jl;
            temp2 += b_val_ij * a_val_jl;
        }
        real sum_temp = *alpha * (temp1 + temp2);
        if (*beta == 0.F) {
            c__[i__ + j * c_dim1] = sum_temp;
        } else {
            c__[i__ + j * c_dim1] = *beta * c__[i__ + j * c_dim1] + sum_temp;
        }
        if (j + 1 <= i__1 && i__ <= j + 1) {
            integer j_next = j + 1;
            temp1 = 0.F;
            temp2 = 0.F;
            for (l = 1; l <= i__3; ++l) {
                temp1 += a[l + i__ * a_dim1] * b[l + j_next * b_dim1];
                temp2 += b[l + i__ * b_dim1] * a[l + j_next * a_dim1];
            }
            real sum_temp_next = *alpha * (temp1 + temp2);
            if (*beta == 0.F) {
                c__[i__ + j_next * c_dim1] = sum_temp_next;
            } else {
                c__[i__ + j_next * c_dim1] = *beta * c__[i__ + j_next * c_dim1] + sum_temp_next;
            }
        }
    }
}
}
