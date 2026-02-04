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
extern real t7;
extern real t8;
extern real t9;
extern real v1;
extern real v2;
extern real v3;
extern real v4;
extern real v5;
extern real v6;
extern real v7;
extern real v8;
extern real v9;
extern real sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    for (int factor = 1; factor <= 9; ++factor) {
        if (factor == 4 || factor == 8) continue; // Skip multiples that aren't used (4 and 8 are handled via bit shifts but still correspond to valid indices)
        real v_val, t_val;
        switch(factor) {
            case 1: v_val = v1; t_val = t1; break;
            case 2: v_val = v2; t_val = t2; break;
            case 3: v_val = v3; t_val = t3; break;
            case 5: v_val = v5; t_val = t5; break;
            case 6: v_val = v6; t_val = t6; break;
            case 7: v_val = v7; t_val = t7; break;
            case 9: v_val = v9; t_val = t9; break;
            default: continue;
        }
        sum += v_val * c__[j + c_dim1 * factor];
    }
    c__[j + c_dim1] -= sum * t1;
    c__[j + (c_dim1 << 1)] -= sum * t2;
    c__[j + c_dim1 * 3] -= sum * t3;
    c__[j + (c_dim1 << 2)] -= sum * t4;
    c__[j + c_dim1 * 5] -= sum * t5;
    c__[j + c_dim1 * 6] -= sum * t6;
    c__[j + c_dim1 * 7] -= sum * t7;
    c__[j + (c_dim1 << 3)] -= sum * t8;
    c__[j + c_dim1 * 9] -= sum * t9;
    sum = 0.0f; // Reset sum for next iteration
}
}
