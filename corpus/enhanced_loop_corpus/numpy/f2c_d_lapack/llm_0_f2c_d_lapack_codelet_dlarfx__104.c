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
extern doublereal t7;
extern doublereal v1;
extern doublereal v2;
extern doublereal v3;
extern doublereal v4;
extern doublereal v5;
extern doublereal v6;
extern doublereal v7;
extern doublereal sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    sum = v1 * c__[j * c_dim1 + 1] + v2 * c__[j * c_dim1 + 2] + v3 * c__[j * c_dim1 + 3] + v4 * c__[j * c_dim1 + 4] + v5 * c__[j * c_dim1 + 5] + v6 * c__[j * c_dim1 + 6] + v7 * c__[j * c_dim1 + 7];
    for (int k = 1; k <= 7; ++k) {
        doublereal t_val = (k == 1) ? t1 : (k == 2) ? t2 : (k == 3) ? t3 : 
                           (k == 4) ? t4 : (k == 5) ? t5 : (k == 6) ? t6 : t7;
        doublereal v_val = (k == 1) ? v1 : (k == 2) ? v2 : (k == 3) ? v3 : 
                           (k == 4) ? v4 : (k == 5) ? v5 : (k == 6) ? v6 : v7;
        c__[j * c_dim1 + k] -= sum * t_val;
    }
}
}
