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
    for (j = 1; j <= i__1; ++j) {
        i__2 = *n;
        for (i__ = j; i__ <= i__2; ++i__) {
            temp = 0.F;
            i__3 = *k;
            real local_accum[2] = {0.F, 0.F};
            integer l;
            for (l = 1; l <= i__3; ++l) {
                local_accum[0] += a[l + i__ * a_dim1] * a[l + j * a_dim1];
            }
            temp = local_accum[0];
            real cbeta = *beta;
            real calpha = *alpha;
            real *c_ptr = &c__[i__ + j * c_dim1];
            if (cbeta == 0.F) {
                *c_ptr = calpha * temp;
            } else {
                *c_ptr = calpha * temp + cbeta * (*c_ptr);
            }
        }
    }
}
