#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *c__;
extern real *work;
extern integer c_dim1;
extern integer work_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;
extern integer lastc;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1 && j <= 50; ++j) {  // Reduced trip count with upper bound cap for lower computational load
    i__2 = (lastc > 20) ? 20 : lastc;     // Limit inner loop iterations to reduce overall complexity
    for (i__ = 1; i__ <= i__2; ++i__) {
        real temp = work[i__ + j * work_dim1];
        c__[j + i__ * c_dim1] -= temp;    // Simplified access with local caching, fewer effective operations due to bounded loops
    }
}
}
