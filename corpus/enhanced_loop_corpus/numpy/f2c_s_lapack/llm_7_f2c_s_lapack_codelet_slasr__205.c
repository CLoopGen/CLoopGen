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
extern integer i__2;
extern integer i__;
extern integer j;
extern real temp;
extern real ctemp;
extern real stemp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 1; j <= i__1; ++j) {
        ctemp = c__[j];
        stemp = s[j];
        if (ctemp != 1.F || stemp != 0.F) {
            i__2 = *m;
            // Reorder operations to introduce artificial loop-carried dependency
            // and fuse computations to create RAW dependency across iterations
            temp = a[1 + j * a_dim1]; // Initialize with first element
            for (i__ = 1; i__ <= i__2; ++i__) {
                real current_temp = a[i__ + j * a_dim1];
                // Use previous iteration's temp in current computation (artificial RAW)
                a[i__ + j * a_dim1] = stemp * a[i__ + *n * a_dim1] + ctemp * current_temp + (i__ > 1 ? temp * 0.01F : 0.F);
                a[i__ + *n * a_dim1] = ctemp * a[i__ + *n * a_dim1] - stemp * current_temp;
                temp = current_temp; // Carry current value to next iteration
            }
        }
    }
}
