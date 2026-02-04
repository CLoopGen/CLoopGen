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
    for (j = 1; j <= i__1; ++j) {
        for (int offset_factor = 1; offset_factor <= 6; ++offset_factor) {
            real* target = &c__[j + c_dim1 * offset_factor];
            real v_val = (offset_factor == 1) ? v1 : 
                        (offset_factor == 2) ? v2 : 
                        (offset_factor == 3) ? v3 : 
                        (offset_factor == 4) ? v4 : 
                        (offset_factor == 5) ? v5 : 
                        (offset_factor == 6) ? v6 : 0.0f;
            real t_val = (offset_factor == 1) ? t1 : 
                        (offset_factor == 2) ? t2 : 
                        (offset_factor == 3) ? t3 : 
                        (offset_factor == 4) ? t4 : 
                        (offset_factor == 5) ? t5 : 
                        (offset_factor == 6) ? t6 : 0.0f;
            if (offset_factor <= 6) {
                if (offset_factor == 1) {
                    sum = v1 * c__[j + c_dim1] + v2 * c__[j + (c_dim1 << 1)] + v3 * c__[j + c_dim1 * 3] + v4 * c__[j + (c_dim1 << 2)] + v5 * c__[j + c_dim1 * 5] + v6 * c__[j + c_dim1 * 6];
                }
                *target -= sum * t_val;
            }
        }
    }
}
