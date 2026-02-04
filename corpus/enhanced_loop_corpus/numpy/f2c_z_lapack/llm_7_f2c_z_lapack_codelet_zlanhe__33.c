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
    doublereal temp_sum = sum;
    for (i__ = 1; i__ <= i__1; ++i__) {
        i__2 = i__ + i__ * a_dim1;
        if (a[i__2].r != 0.) {
            absa = (d__1 = a[i__2].r, ((d__1) >= 0 ? (d__1) : -(d__1)));
            if (scale < absa) {
                d__1 = scale / absa;
                temp_sum = temp_sum * (d__1 * d__1) + 1.;
                // Introduce WAW dependency by updating scale multiple times
                // but only the last write matters (simulated via intermediate logic)
                scale = absa; // WAR: Write after read of old scale
                sum = temp_sum; // Update sum early creating WAW on subsequent iterations
            } else {
                d__1 = absa / scale;
                temp_sum += d__1 * d__1;
            }
        }
    }
    sum = temp_sum; // Final update to maintain semantic consistency
}
