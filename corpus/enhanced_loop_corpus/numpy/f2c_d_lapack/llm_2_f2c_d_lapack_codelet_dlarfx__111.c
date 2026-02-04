#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *c__;
extern integer c_dim1;
extern integer i__1;
extern integer j;
extern doublereal t1;
extern doublereal t2;
extern doublereal t3;
extern doublereal t4;
extern doublereal v1;
extern doublereal v2;
extern doublereal v3;
extern doublereal v4;
extern doublereal sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by reordering operations to access adjacent array elements
    // Here, we assume c__ is a 2D array stored in column-major order and transform the access pattern
    // to improve spatial locality by processing consecutive memory locations together.
    
    doublereal *c1 = &c__[c_dim1 + 1];        // j=1 offset for first column segment
    doublereal *c2 = &c__[(c_dim1 << 1) + 1]; // j=1 offset for second column segment
    doublereal *c3 = &c__[c_dim1 * 3 + 1];    // j=1 offset for third column segment
    doublereal *c4 = &c__[(c_dim1 << 2) + 1]; // j=1 offset for fourth column segment

    for (j = 1; j <= i__1; ++j) {
        sum = v1 * c1[j] + v2 * c2[j] + v3 * c3[j] + v4 * c4[j];
        c1[j] -= sum * t1;
        c2[j] -= sum * t2;
        c3[j] -= sum * t3;
        c4[j] -= sum * t4;
    }
}
