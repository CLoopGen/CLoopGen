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
extern integer i__;
extern integer j;
extern real sum;
extern real value;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    real local_value = 0.F;
    for (j = 1; j <= i__1; ++j) {
        sum = 0.F;
        i__2 = *m;
        for (i__ = 1; i__ <= i__2; ++i__) {
            r__1 = a[i__ + j * a_dim1];
            sum += (r__1 >= 0 ? r__1 : -r__1);
        }
        if (sum > local_value) {
            local_value = sum;
        }
    }
    value = local_value;
}
