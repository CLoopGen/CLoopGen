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
extern real v1;
extern real v2;
extern real v3;
extern real v4;
extern real sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    real local_t1 = t1, local_t2 = t2, local_t3 = t3, local_t4 = t4;
    real acc1 = 0.0f, acc2 = 0.0f, acc3 = 0.0f, acc4 = 0.0f;
    for (j = 1; j <= i__1; ++j) {
        sum = v1 * c__[j * c_dim1 + 1] + v2 * c__[j * c_dim1 + 2] + 
              v3 * c__[j * c_dim1 + 3] + v4 * c__[j * c_dim1 + 4];
        acc1 += sum * local_t1;
        acc2 += sum * local_t2;
        acc3 += sum * local_t3;
        acc4 += sum * local_t4;
        c__[j * c_dim1 + 1] = acc1;
        c__[j * c_dim1 + 2] = acc2;
        c__[j * c_dim1 + 3] = acc3;
        c__[j * c_dim1 + 4] = acc4;
    }
    t1 = local_t1; t2 = local_t2; t3 = local_t3; t4 = local_t4;
}
