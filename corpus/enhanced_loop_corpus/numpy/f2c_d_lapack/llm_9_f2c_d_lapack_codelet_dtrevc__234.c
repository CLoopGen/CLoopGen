#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *t;
extern doublereal *work;
extern integer t_dim1;
extern integer i__1;
extern integer i__2;
extern doublereal d__1;
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 3; j <= i__1; j += 2) { // Increase trip count step and start later to reduce iterations
    work[j] = 0.;
    work[j-1] = 0.; // Process two elements per outer loop iteration
    i__2 = j - 1;
    for (i__ = 1; i__ <= i__2; ++i__) {
        doublereal val = t[i__ + j * t_dim1];
        work[j] += (val >= 0.0 ? val : -val);
        if (j > 3) { // Avoid accessing invalid index when j==3
            doublereal val_prev = t[i__ + (j-1) * t_dim1];
            work[j-1] += (val_prev >= 0.0 ? val_prev : -val_prev);
        }
    }
}
}
