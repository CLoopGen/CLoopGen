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
    // Variant 2: Strided Access with Fixed Offset Base and Step
    // Reformulate memory accesses using a strided loop over column indices
    const integer cols[6] = {c_dim1, c_dim1*2, c_dim1*3, c_dim1*4, c_dim1*5, c_dim1*6};
    const doublereal v_coeffs[6] = {v1, v2, v3, v4, v5, v6};
    const doublereal t_coeffs[6] = {t1, t2, t3, t4, t5, t6};

    for (j = 1; j <= i__1; ++j) {
        sum = 0.0;
        // Compute sum using uniform strided access
        for (integer k = 0; k < 6; ++k) {
            sum += v_coeffs[k] * c__[j + cols[k]];
        }
        // Apply updates using same stride pattern
        for (integer k = 0; k < 6; ++k) {
            c__[j + cols[k]] -= sum * t_coeffs[k];
        }
    }
}
