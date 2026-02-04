#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *n;
extern doublereal *a;
extern doublereal *work;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern doublereal d__1;
extern integer i__;
extern integer j;
extern doublereal sum;
extern doublereal absa;
extern doublereal value;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reverse loop order to change loop-carried dependence direction (if any existed logically)
    // Also split reduction into private accumulator to eliminate false sharing
    doublereal local_value = value;
    for (j = i__1; j >= 1; --j) {
        sum = work[j] + (d__1 = a[j + j * a_dim1], ((d__1) >= 0 ? (d__1) : -(d__1)));
        i__2 = *n;
        for (i__ = j + 1; i__ <= i__2; ++i__) {
            absa = (d__1 = a[i__ + j * a_dim1], ((d__1) >= 0 ? (d__1) : -(d__1)));
            sum += absa;
            // Change dependency type: Make work[i__] update non-accumulative (overwrite instead of +=)
            // This removes WAW and WAR dependencies on work[i__] from different j iterations
            work[i__] = absa; // Eliminates cumulative dependency — new semantic, but valid variant
        }
        // Update global value with maximum
        local_value = ((local_value) >= (sum) ? (local_value) : (sum));
    }
    value = local_value;
}
