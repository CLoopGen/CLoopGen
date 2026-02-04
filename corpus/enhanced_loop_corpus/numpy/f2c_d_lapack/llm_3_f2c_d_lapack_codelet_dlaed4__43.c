#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *i__;
extern doublereal *d__;
extern doublereal *delta;
extern integer i__1;
extern integer j;
extern doublereal midpt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive Access with Offset Base (forward traversal using pointer arithmetic)
    doublereal *d_ptr = &d__[1];
    doublereal *delta_ptr = &delta[1];
    doublereal d_i_val = d__[*i__]; // Load once for reuse

    for (j = 1; j <= i__1; ++j) {
        *delta_ptr = *d_ptr - d_i_val - midpt;
        d_ptr++;
        delta_ptr++;
    }
}
