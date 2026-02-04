#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;

extern integer *m;
extern doublecomplex *a;
extern integer a_dim1;
extern integer ret_val;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    integer prev_i = *m;
    for (j = 1; j <= i__1; ++j) {
        integer found = 0;
        for (i__ = prev_i; i__ >= 1; --i__) {
            i__2 = i__ + j * a_dim1;
            if (a[i__2].r != 0. || a[i__2].i != 0.) {
                ret_val = (ret_val >= i__) ? ret_val : i__;
                prev_i = i__; // Introduce loop-carried dependence: current i influences next loop's starting point
                found = 1;
                break;
            }
        }
        if (!found) {
            prev_i = (*m >= prev_i) ? *m : prev_i; // Reset or maintain if no element found
        }
    }
}
