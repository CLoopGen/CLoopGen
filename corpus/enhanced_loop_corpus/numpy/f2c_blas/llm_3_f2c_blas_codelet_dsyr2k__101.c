#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *k;
extern doublereal *alpha;
extern doublereal *a;
extern doublereal *b;
extern doublereal *beta;
extern doublereal *c__;
extern integer a_dim1;
extern integer b_dim1;
extern integer c_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__;
extern integer j;
extern integer l;
extern doublereal temp1;
extern doublereal temp2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Use strided memory access by unrolling and accessing elements with larger strides
// This variant simulates a transposed-like access pattern with increased stride
for (j = 1; j <= i__1; j += 2) {  // Stride of 2 on outer loop
    i__2 = (j + 1 <= i__1) ? j + 1 : j;  // Handle boundary
    for (i__ = 1; i__ <= i__2; ++i__) {
        temp1 = 0.;
        temp2 = 0.;
        i__3 = *k;
        // Access memory with non-unit stride (every second element)
        for (l = 1; l <= i__3; l += 2) {
            // Strided access: step by 2, handle bounds
            temp1 += a[l + i__ * a_dim1] * b[l + j * b_dim1];
            if (l + 1 <= i__3) {
                temp1 += a[(l+1) + i__ * a_dim1] * b[(l+1) + j * b_dim1];
            }
            temp2 += b[l + i__ * b_dim1] * a[l + j * a_dim1];
            if (l + 1 <= i__3) {
                temp2 += b[(l+1) + i__ * b_dim1] * a[(l+1) + j * a_dim1];
            }
        }
        if (*beta == 0.) {
            c__[i__ + j * c_dim1] = *alpha * temp1 + *alpha * temp2;
        } else {
            c__[i__ + j * c_dim1] = *beta * c__[i__ + j * c_dim1] + *alpha * temp1 + *alpha * temp2;
        }
        // Process next column if within bounds
        if (j + 1 <= i__1) {
            integer j2 = j + 1;
            temp1 = 0.;
            temp2 = 0.;
            for (l = 1; l <= i__3; l += 2) {
                temp1 += a[l + i__ * a_dim1] * b[l + j2 * b_dim1];
                if (l + 1 <= i__3) {
                    temp1 += a[(l+1) + i__ * a_dim1] * b[(l+1) + j2 * b_dim1];
                }
                temp2 += b[l + i__ * b_dim1] * a[l + j2 * a_dim1];
                if (l + 1 <= i__3) {
                    temp2 += b[(l+1) + i__ * b_dim1] * a[(l+1) + j2 * a_dim1];
                }
            }
            if (*beta == 0.) {
                c__[i__ + j2 * c_dim1] = *alpha * temp1 + *alpha * temp2;
            } else {
                c__[i__ + j2 * c_dim1] = *beta * c__[i__ + j2 * c_dim1] + *alpha * temp1 + *alpha * temp2;
            }
        }
    }
}
}
