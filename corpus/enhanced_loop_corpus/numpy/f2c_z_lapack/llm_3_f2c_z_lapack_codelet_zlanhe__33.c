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
    // Variant 2: Consecutive access via precomputed index array to simulate indirect but sequential traversal
    integer* indices = (integer*)malloc(i__1 * sizeof(integer));
    if (indices == NULL) return;

    for (integer j = 0; j < i__1; ++j) {
        indices[j] = (j + 1) + (j + 1) * a_dim1;  // Precompute diagonal indices
    }

    for (i__ = 0; i__ < i__1; ++i__) {
        integer idx = indices[i__];
        if (a[idx].r != 0.) {
            absa = (d__1 = a[idx].r, ((d__1) >= 0 ? (d__1) : -(d__1)));
            if (scale < absa) {
                d__1 = scale / absa;
                sum = sum * (d__1 * d__1) + 1.;
                scale = absa;
            } else {
                d__1 = absa / scale;
                sum += d__1 * d__1;
            }
        }
    }

    free(indices);
}
