#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced trip count and modified nesting to decrease computational load
    if (i__1 >= 2) {
        a[2 * a_dim1 + 1] = 0.; // Initialize first valid j index
        for (j = 4; j <= i__1; j += 2) { // Process every second j, reducing outer loop iterations
            i__ = j - 1;
            if (i__ >= 2) {
                a[i__ + j * a_dim1] = a[i__ - 1 + j * a_dim1]; // Single assignment without loop
            }
            a[j * a_dim1 + 1] = 0.;
        }
    }
}
