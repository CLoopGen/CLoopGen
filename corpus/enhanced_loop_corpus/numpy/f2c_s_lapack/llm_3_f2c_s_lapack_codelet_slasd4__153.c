#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *n;
extern real *z__;
extern real *delta;
extern real *work;
extern integer i__1;
extern integer j;
extern real phi;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive access with temporary accumulation to simulate reordered computation
    // Ensures all elements from i__1 to *n are processed in reverse, but uses a forward-like pattern via index remapping
    integer start = i__1;
    integer end = *n;
    for (j = 0; j <= (end - start); ++j) {
        integer idx = end - j;  // Reverse indexing: map sequential j to descending array index
        phi += z__[idx] * z__[idx] / (work[idx] * delta[idx]);
    }
}
