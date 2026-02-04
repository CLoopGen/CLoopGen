#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *z__;
extern doublereal *delta;
extern doublereal *work;
extern integer i__1;
extern integer j;
extern doublereal psi;
extern doublereal dpsi;
extern doublereal temp;
extern doublereal erretm;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access pattern with stride of 2, processing every second element first,
    // then the second pass on the odd-offset elements. This changes access locality and may help
    // in scenarios where data alignment or cache conflicts are an issue.

    integer j;
    // First pass: even indices (assuming 1-based indexing, so j = 2, 4, 6, ...)
    for (j = 2; j <= i__1; j += 2) {
        temp = z__[j] / (work[j] * delta[j]);
        psi += z__[j] * temp;
        dpsi += temp * temp;
        erretm += psi;
    }
    // Second pass: odd indices (j = 1, 3, 5, ...)
    for (j = 1; j <= i__1; j += 2) {
        temp = z__[j] / (work[j] * delta[j]);
        psi += z__[j] * temp;
        dpsi += temp * temp;
        erretm += psi;
    }
}
