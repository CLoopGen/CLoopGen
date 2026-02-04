#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *vt;
extern doublereal *vt2;
extern integer vt_dim1;
extern integer vt2_dim1;
extern integer i__1;
extern doublereal c__;
extern integer i__;
extern integer m;
extern doublereal s;
extern integer nlp1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access with Fixed Stride Simulation (access every second element logic, adjusted to fit bounds)
    integer stride = 2;
    integer limit = (i__1 + stride - 1) / stride; // Ceiling division to cover all elements with stride
    for (i__ = 1; i__ <= limit; ++i__) {
        integer j = 1 + (i__ - 1) * stride; // Compute actual index in original sequence
        if (j <= i__1) {
            vt[m + j * vt_dim1] = -s * vt[nlp1 + j * vt_dim1];
            vt2[j * vt2_dim1 + 1] = c__ * vt[nlp1 + j * vt_dim1];
        }
    }
}
