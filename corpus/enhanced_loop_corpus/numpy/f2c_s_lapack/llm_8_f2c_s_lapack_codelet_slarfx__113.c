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
    // Variant 1: Increased computational intensity with additional arithmetic operations and reduced trip count
    integer j_step = 2;
    for (j = 1; j <= i__1; j += j_step) {
        sum = v1 * c__[j + c_dim1] + v2 * c__[j + (c_dim1 << 1)] + v3 * c__[j + c_dim1 * 3] + 
              v4 * c__[j + (c_dim1 << 2)] + v5 * c__[j + c_dim1 * 5] + v6 * c__[j + c_dim1 * 6];
        
        // Additional computational steps to increase arithmetic intensity
        real temp1 = sum * t1;
        real temp2 = sum * t2;
        real temp3 = sum * t3;
        real temp4 = sum * t4;
        real temp5 = sum * t5;
        real temp6 = sum * t6;

        c__[j + c_dim1] = c__[j + c_dim1] - temp1 - temp2;
        c__[j + (c_dim1 << 1)] = c__[j + (c_dim1 << 1)] - temp2 - temp3;
        c__[j + c_dim1 * 3] = c__[j + c_dim1 * 3] - temp3 - temp4;
        c__[j + (c_dim1 << 2)] = c__[j + (c_dim1 << 2)] - temp4 - temp5;
        c__[j + c_dim1 * 5] = c__[j + c_dim1 * 5] - temp5 - temp6;
        c__[j + c_dim1 * 6] = c__[j + c_dim1 * 6] - temp6 - temp1;

        // Perform extra dummy computation to increase workload per iteration
        sum += sum * 0.5f + v1 * v2;
    }
}
