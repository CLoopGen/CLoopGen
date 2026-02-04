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
    // Variant 2: Strided Memory Access with Reverse Iteration Order
    // Instead of forward access, we traverse the loop backwards with explicit striding
    // This creates a different memory access pattern that may expose pipeline or prefetch differences

    for (i__ = i__1; i__ >= nlp2; --i__) {
        integer idx_vt = m + i__ * vt_dim1;
        integer idx_vt2 = i__ * vt2_dim1 + 1;

        // Apply same computation but in reverse order with explicit indexing
        real temp = vt[idx_vt];
        vt2[idx_vt2] = s * temp;
        vt[idx_vt] = c__ * temp;
    }
}
