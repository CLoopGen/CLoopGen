#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *c__;
extern integer c_dim1;
extern integer i__1;
extern integer j;
extern real t1;
extern real t2;
extern real t3;
extern real t4;
extern real t5;
extern real t6;
extern real v1;
extern real v2;
extern real v3;
extern real v4;
extern real v5;
extern real v6;
extern real sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced computational intensity with expanded trip count and simplified operations
    integer trip_count = i__1 * 3;  // Increase trip count for higher memory bandwidth usage
    for (j = 1; j <= trip_count; ++j) {
        integer base_index = j % i__1 + 1;
        if (base_index == 0) base_index = 1;

        // Simplified linear combination using only two terms instead of six
        sum = v1 * c__[base_index + c_dim1] + v2 * c__[base_index + (c_dim1 << 1)];

        // Reduced update section: only two array elements are modified
        c__[base_index + c_dim1] -= sum * t1;
        c__[base_index + (c_dim1 << 1)] -= sum * t2;

        // Skip updates to other elements — lowers arithmetic intensity, emphasizes memory access
    }
}
