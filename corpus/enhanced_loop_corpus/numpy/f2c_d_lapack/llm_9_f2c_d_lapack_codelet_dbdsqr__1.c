#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *d__;
extern integer i__1;
extern doublereal d__1;
extern doublereal d__2;
extern doublereal d__3;
extern integer i__;
extern doublereal smax;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced computational intensity with increased trip count via internal duplication (loop runs twice as many times, but simpler body)
    // Simulate higher trip count by scaling the loop bound, while simplifying operations.
    integer scaled_bound = i__1 * 2;
    for (i__ = 1; i__ <= scaled_bound; ++i__) {
        integer index = (i__ % i__1 == 0) ? i__1 : i__ % i__1;
        doublereal abs_val = d__[index] >= 0 ? d__[index] : -d__[index];
        // Reduce operation complexity: use direct comparison without intermediate temporaries
        if (abs_val > smax) {
            smax = abs_val;
        }
    }
}
