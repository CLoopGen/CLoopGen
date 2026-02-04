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
extern integer nlp2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access Pattern
    // Introduce a stride factor to access every second element (stride of 2)
    // This changes the iteration to step by 2, creating a strided access pattern
    integer stride = 2;
    integer i__max = i__1 - (i__1 - nlp2) % stride;  // Align end index to stride
    for (i__ = nlp2; i__ <= i__max; i__ += stride) {
        vt2[i__ * vt2_dim1 + 1] = s * vt[m + i__ * vt_dim1];
        vt[m + i__ * vt_dim1] = c__ * vt[m + i__ * vt_dim1];
    }
}
