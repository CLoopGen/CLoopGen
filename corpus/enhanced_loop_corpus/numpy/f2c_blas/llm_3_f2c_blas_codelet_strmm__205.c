#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

typedef int logical;

extern integer *m;
extern real *alpha;
extern real *a;
extern real *b;
extern integer a_dim1;
extern integer b_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;
extern integer k;
extern real temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Introduce strided memory access with fixed stride on array 'a'
    // Simulate a blocked/strided access pattern on matrix 'a' by accessing every 2nd element in inner loop
    // This models scenarios where data alignment or padding causes non-unit strides
    // We maintain functional equivalence by ensuring all required indices are still accessed appropriately
    for (j = 1; j <= i__1; ++j) {
        for (k = *m; k >= 1; --k) {
            if (b[k + j * b_dim1] != 0.F) {
                temp = *alpha * b[k + j * b_dim1];
                b[k + j * b_dim1] = temp;
                if (nounit) {
                    b[k + j * b_dim1] *= a[k + k * a_dim1];
                }
                i__2 = *m;
                // Use strided access: step by 2, then handle remainder with second pass if needed
                // First pass: even offsets relative to k+1
                integer start = k + 1;
                for (i__ = start; i__ <= i__2; i__ += 2) {
                    b[i__ + j * b_dim1] += temp * a[i__ + k * a_dim1];
                }
                // Second pass: odd offsets (shifted by 1)
                for (i__ = start + 1; i__ <= i__2; i__ += 2) {
                    b[i__ + j * b_dim1] += temp * a[i__ + k * a_dim1];
                }
            }
        }
    }
}
