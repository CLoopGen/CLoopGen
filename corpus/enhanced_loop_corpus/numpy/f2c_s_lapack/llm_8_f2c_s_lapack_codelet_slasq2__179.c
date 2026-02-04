#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

typedef double doublereal;

extern real *z__;
extern integer i__1;
extern real r__1;
extern real r__2;
extern real d__;
extern integer k;
extern integer i0;
extern integer i4;
extern integer n0;
extern integer pp;
extern real tol2;
extern real emin;
extern real temp;
extern real qmax;
extern real safmin;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 1; k <= 2; ++k) {
    d__ = z__[(n0 << 2) + pp - 3];
    i__1 = (i0 << 2) + pp;
    real prev_z_value = d__;
    for (i4 = (n0 - 1 << 2) + pp; i4 >= i__1; i4 += -4) {
        real local_dependency = prev_z_value;
        if (z__[i4 - 1] <= tol2 * local_dependency) {
            z__[i4 - 1] = -0.F;
            prev_z_value = z__[i4 - 3];
        } else {
            prev_z_value = z__[i4 - 3] * (local_dependency / (local_dependency + z__[i4 - 1]));
        }
    }
    d__ = prev_z_value;
    emin = z__[(i0 << 2) + pp + 1];
    i__1 = (n0 - 1 << 2) + pp;
    real running_d = z__[(i0 << 2) + pp - 3];
    real min_local = emin;
    for (i4 = (i0 << 2) + pp; i4 <= i__1; i4 += 4) {
        real new_sum = running_d + z__[i4 - 1];
        z__[i4 - (pp << 1) - 2] = new_sum;
        if (z__[i4 - 1] <= tol2 * running_d) {
            z__[i4 - 1] = -0.F;
            z__[i4 - (pp << 1) - 2] = running_d;
            z__[i4 - (pp << 1)] = 0.F;
            running_d = z__[i4 + 1];
        } else if (safmin * z__[i4 + 1] < new_sum && safmin * new_sum < z__[i4 + 1]) {
            temp = z__[i4 + 1] / new_sum;
            z__[i4 - (pp << 1)] = z__[i4 - 1] * temp;
            running_d *= temp;
        } else {
            z__[i4 - (pp << 1)] = z__[i4 + 1] * (z__[i4 - 1] / new_sum);
            running_d = z__[i4 + 1] * (running_d / new_sum);
        }
        r__1 = min_local , r__2 = z__[i4 - (pp << 1)];
        min_local = (doublereal)((r__1) <= (r__2) ? (r__1) : (r__2));
    }
    emin = min_local;
    z__[(n0 << 2) - pp - 2] = running_d;
    d__ = running_d;
    qmax = z__[(i0 << 2) - pp - 2];
    i__1 = (n0 << 2) - pp - 2;
    for (i4 = (i0 << 2) - pp + 2; i4 <= i__1; i4 += 4) {
        r__1 = qmax , r__2 = z__[i4];
        qmax = (doublereal)((r__1) >= (r__2) ? (r__1) : (r__2));
    }
    pp = 1 - pp;
}
}
