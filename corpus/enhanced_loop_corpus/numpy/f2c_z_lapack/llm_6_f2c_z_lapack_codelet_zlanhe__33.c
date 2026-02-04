#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;

typedef int integer;

extern doublecomplex *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern doublereal d__1;
extern integer i__;
extern doublereal sum;
extern doublereal absa;
extern doublereal scale;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    doublereal local_scale = scale;
    doublereal local_sum = sum;
    for (i__ = 1; i__ <= i__1; ++i__) {
        i__2 = i__ + i__ * a_dim1;
        if (a[i__2].r != 0.) {
            absa = (d__1 = a[i__2].r, ((d__1) >= 0 ? (d__1) : -(d__1)));
            if (local_scale < absa) {
                d__1 = local_scale / absa;
                local_sum = local_sum * (d__1 * d__1) + 1.;
                local_scale = absa;
            } else {
                d__1 = absa / local_scale;
                local_sum += d__1 * d__1;
            }
        }
    }
    sum = local_sum;
    scale = local_scale;
}
