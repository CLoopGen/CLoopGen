#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *m;
extern integer *n;
extern real *c__;
extern real *s;
extern real *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__;
extern integer j;
extern real temp;
extern real ctemp;
extern real stemp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Memory Access Pattern Modification - Strided Access with Reverse Iteration Order
    for (j = *m - 1; j >= 1; --j) {
        ctemp = c__[j];
        stemp = s[j];
        if (ctemp != 1.F || stemp != 0.F) {
            i__1 = *n;
            // Process column indices in reverse order with stride of 2, then handle odd indices
            integer stride = 2;
            // First pass: even strides (reverse)
            for (i__ = i__1 - (i__1 % 2); i__ >= 1; i__ -= stride) {
                temp = a[j + i__ * a_dim1];
                a[j + i__ * a_dim1] = stemp * a[*m + i__ * a_dim1] + ctemp * temp;
                a[*m + i__ * a_dim1] = ctemp * a[*m + i__ * a_dim1] - stemp * temp;
            }
            // Second pass: fill in the skipped indices (odd positions)
            for (i__ = i__1 - ((i__1 + 1) % 2); i__ >= 1; --i__) {
                if (i__ % 2 == 0) continue; // Skip already processed
                temp = a[j + i__ * a_dim1];
                a[j + i__ * a_dim1] = stemp * a[*m + i__ * a_dim1] + ctemp * temp;
                a[*m + i__ * a_dim1] = ctemp * a[*m + i__ * a_dim1] - stemp * temp;
            }
        }
    }
}
