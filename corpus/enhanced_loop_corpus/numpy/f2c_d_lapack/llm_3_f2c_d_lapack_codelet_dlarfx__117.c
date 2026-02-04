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
extern doublereal t8;
extern doublereal t9;
extern doublereal v1;
extern doublereal v2;
extern doublereal v3;
extern doublereal v4;
extern doublereal v5;
extern doublereal v6;
extern doublereal v7;
extern doublereal v8;
extern doublereal v9;
extern doublereal t10;
extern doublereal v10;
extern doublereal sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
const integer offsets[] = {c_dim1, c_dim1 << 1, c_dim1 * 3, c_dim1 << 2, c_dim1 * 5, c_dim1 * 6, c_dim1 * 7, c_dim1 << 3, c_dim1 * 9, c_dim1 * 10};
const doublereal v_coeffs[] = {v1, v2, v3, v4, v5, v6, v7, v8, v9, v10};
const doublereal t_coeffs[] = {t1, t2, t3, t4, t5, t6, t7, t8, t9, t10};

for (j = 1; j <= i__1; ++j) {
    sum = 0.0;
    for (int k = 0; k < 10; ++k) {
        sum += v_coeffs[k] * c__[j + offsets[k]];
    }
    for (int k = 0; k < 10; ++k) {
        c__[j + offsets[k]] -= sum * t_coeffs[k];
    }
}
}
