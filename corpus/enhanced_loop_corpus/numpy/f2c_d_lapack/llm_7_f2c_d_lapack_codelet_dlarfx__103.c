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
extern doublereal t4;
extern doublereal t5;
extern doublereal t6;
extern doublereal v1;
extern doublereal v2;
extern doublereal v3;
extern doublereal v4;
extern doublereal v5;
extern doublereal v6;
extern doublereal sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    doublereal local_t1 = t1, local_t2 = t2, local_t3 = t3, local_t4 = t4, local_t5 = t5, local_t6 = t6;
    doublereal acc1 = 0.0, acc2 = 0.0, acc3 = 0.0, acc4 = 0.0, acc5 = 0.0, acc6 = 0.0;
    for (j = 1; j <= i__1; ++j) {
        sum = v1 * c__[j * c_dim1 + 1] + v2 * c__[j * c_dim1 + 2] + v3 * c__[j * c_dim1 + 3] +
              v4 * c__[j * c_dim1 + 4] + v5 * c__[j * c_dim1 + 5] + v6 * c__[j * c_dim1 + 6];
        acc1 += sum * local_t1;
        acc2 += sum * local_t2;
        acc3 += sum * local_t3;
        acc4 += sum * local_t4;
        acc5 += sum * local_t5;
        acc6 += sum * local_t6;
    }
    for (j = 1; j <= i__1; ++j) {
        c__[j * c_dim1 + 1] -= acc1;
        c__[j * c_dim1 + 2] -= acc2;
        c__[j * c_dim1 + 3] -= acc3;
        c__[j * c_dim1 + 4] -= acc4;
        c__[j * c_dim1 + 5] -= acc5;
        c__[j * c_dim1 + 6] -= acc6;
    }
}
