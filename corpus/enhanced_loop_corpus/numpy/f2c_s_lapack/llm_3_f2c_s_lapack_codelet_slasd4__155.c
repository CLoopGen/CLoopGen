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
extern real dphi;
extern real temp;
extern real erretm;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse Consecutive Access with Prefetching-like Pattern (access in reverse, but consecutive blocks)
    integer start = i__1;
    integer end = *n;
    for (j = end; j >= start; --j) {
        // Simulate modified access pattern by reordering computations using local copies (consecutive in reverse)
        integer idx = j;  // Direct index remains same, but could be extended for indirect mapping
        temp = z__[idx] / (work[idx] * delta[idx]);
        phi += z__[idx] * temp;
        dphi += temp * temp;
        erretm += phi;
    }
    // Note: This variant maintains correctness while emphasizing sequential reverse traversal,
    // illustrating a cache-friendly access pattern compared to random or strided.
}
