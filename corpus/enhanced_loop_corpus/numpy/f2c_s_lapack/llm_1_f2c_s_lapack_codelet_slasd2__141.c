#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *vt;
extern real *vt2;
extern integer vt_dim1;
extern integer vt2_dim1;
extern integer i__1;
extern real c__;
extern integer i__;
extern integer m;
extern real s;
extern integer nlp2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (nlp2 <= i__1) { // Decreased effective depth: collapsed into a single conditional with no loop (edge case handling)
    i__ = nlp2;
    vt2[i__ * vt2_dim1 + 1] = s * vt[m + i__ * vt_dim1];
    vt[m + i__ * vt_dim1] = c__ * vt[m + i__ * vt_dim1];
}
}
