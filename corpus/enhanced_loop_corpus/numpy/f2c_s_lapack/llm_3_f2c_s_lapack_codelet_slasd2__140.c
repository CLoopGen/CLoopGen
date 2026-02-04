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
extern integer nlp1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access with Reverse Iteration Pattern
    // Instead of forward unit-stride access, we traverse the arrays with reverse indexing and fixed stride.
    // This simulates scenarios where data is accessed non-sequentially (e.g., in blocked or transposed layouts).
    // The arithmetic adjusts the index to jump by fixed increments, mimicking strided array sections.

    const integer stride = vt_dim1;  // Original stride factor
    const integer stride2 = vt2_dim1;

    for (i__ = i__1; i__ >= 1; --i__) {
        integer idx_vt_nlp1 = nlp1 * stride + i__ * stride;
        integer idx_vt_m = m * stride + i__ * stride;
        integer idx_vt2 = i__ * stride2 + 1;

        real temp_val = vt[idx_vt_nlp1];
        vt[idx_vt_m] = -s * temp_val;
        vt2[idx_vt2] = c__ * temp_val;
    }
}
