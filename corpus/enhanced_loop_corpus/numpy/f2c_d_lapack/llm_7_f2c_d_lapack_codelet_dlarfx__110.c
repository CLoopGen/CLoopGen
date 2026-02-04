#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *c__;
extern integer c_dim1;
extern integer i__1;
extern integer j;
extern doublereal t1;
extern doublereal t2;
extern doublereal t3;
extern doublereal v1;
extern doublereal v2;
extern doublereal v3;
extern doublereal sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    doublereal local_v1 = v1, local_v2 = v2, local_v3 = v3;
    doublereal local_t1 = t1, local_t2 = t2, local_t3 = t3;
    doublereal sum_val;
    for (j = 1; j <= i__1; ++j) {
        sum_val = local_v1 * c__[j + c_dim1];
        sum_val += local_v2 * c__[j + (c_dim1 << 1)];
        sum_val += local_v3 * c__[j + c_dim1 * 3];
        
        c__[j + c_dim1] = c__[j + c_dim1] - sum_val * local_t1;
        c__[j + (c_dim1 << 1)] = c__[j + (c_dim1 << 1)] - sum_val * local_t2;
        c__[j + c_dim1 * 3] = c__[j + c_dim1 * 3] - sum_val * local_t3;
    }
}
