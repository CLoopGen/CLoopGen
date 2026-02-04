#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

typedef int logical;

extern integer *m;
extern doublereal *alpha;
extern doublereal *a;
extern doublereal *b;
extern integer a_dim1;
extern integer b_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__;
extern integer j;
extern integer k;
extern doublereal temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Change memory access pattern to favor consecutive writes by reordering loops (j and i__ swapped in inner loop)
    // This variant attempts to improve spatial locality in b by iterating over rows (i__) first, then columns (j), 
    // making accesses to b[i__ + j * b_dim1] more cache-friendly when b is stored in column-major order.
    
    for (k = 1; k <= i__1; ++k) {
        i__2 = k - 1;
        for (j = 1; j <= i__2; ++j) {
            if (a[j + k * a_dim1] != 0.) {
                temp = *alpha * a[j + k * a_dim1];
                i__3 = *m;
                // Interchange inner loop order to access b[i__ + j*b_dim1] and b[i__ + k*b_dim1] consecutively across i__
                for (i__ = 1; i__ <= i__3; ++i__) {
                    b[i__ + j * b_dim1] += temp * b[i__ + k * b_dim1];
                }
            }
        }
        temp = *alpha;
        if (nounit) {
            temp *= a[k + k * a_dim1];
        }
        if (temp != 1.) {
            i__2 = *m;
            for (i__ = 1; i__ <= i__2; ++i__) {
                b[i__ + k * b_dim1] = temp * b[i__ + k * b_dim1];
            }
        }
    }
}
