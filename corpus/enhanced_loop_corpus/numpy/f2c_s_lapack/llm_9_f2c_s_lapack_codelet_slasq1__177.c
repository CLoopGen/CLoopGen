#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *work;
extern integer i__1;
extern real r__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i__ = 1; i__ <= i__1 * 2; ++i__) { // Doubled trip count for higher computational load
    if (i__ <= i__1) {
        r__1 = work[i__];
        work[i__] = r__1 * r__1;
    }
}
}
