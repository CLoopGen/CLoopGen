#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

typedef double doublereal;

extern integer *m;
extern real *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern real r__1;
extern real r__2;
extern real r__3;
extern integer i__;
extern integer j;
extern real value;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    real local_max = 0.0f;
    for (j = 1; j <= i__1; ++j) {
        real row_max = 0.0f;
        i__2 = *m;
        for (i__ = 1; i__ <= i__2; ++i__) {
            r__1 = a[i__ + j * a_dim1];
            real abs_val = (r__1 >= 0) ? r__1 : -r__1;
            if (abs_val > row_max) {
                row_max = abs_val;
            }
        }
        if (row_max > local_max) {
            local_max = row_max;
        }
    }
    value = (real)((value) >= (local_max) ? value : local_max);
}
