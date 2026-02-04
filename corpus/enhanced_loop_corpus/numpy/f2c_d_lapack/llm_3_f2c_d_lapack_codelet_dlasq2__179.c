#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *z__;
extern integer i__1;
extern doublereal d__1;
extern doublereal d__2;
extern doublereal d__;
extern integer k;
extern integer i0;
extern integer i4;
extern integer n0;
extern integer pp;
extern doublereal tol2;
extern doublereal emin;
extern doublereal temp;
extern doublereal qmax;
extern doublereal safmin;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Variant 2: Memory Access Pattern Modification - Use indirect addressing via pointer arithmetic with stride simulation
// Replace direct indexing with pointers advanced by fixed strides to simulate structured access patterns.
for (k = 1; k <= 2; ++k) {
    doublereal* z_n0_ptr = &z__[(n0 << 2) + pp];
    d__ = *(z_n0_ptr - 3);

    doublereal* z_i0_ptr = &z__[(i0 << 2) + pp];
    doublereal* z_n0m1_ptr = &z__[(n0 - 1 << 2) + pp];

    // Backward pass using pointer decrements (stride -4 corresponds to --ptr twice due to double spacing?)
    // Assuming each logical element is 4 bytes apart in index space, but we treat as unit steps in pointer
    for (doublereal* p = z_n0m1_ptr; p >= z_i0_ptr; p -= 4) {
        if (*(p - 1) <= tol2 * d__) {
            *(p - 1) = -0.;
            d__ = *(p - 3);
        } else {
            d__ = *(p - 3) * (d__ / (d__ + *(p - 1)));
        }
    }

    emin = z__[(i0 << 2) + pp + 1];
    d__ = z__[(i0 << 2) + pp - 3];

    doublereal* fwd_start = &z__[(i0 << 2) + pp];
    doublereal* fwd_end = &z__[(n0 - 1 << 2) + pp];

    // Forward pass with indirect writes using computed offsets through pointer arithmetic
    for (doublereal* p = fwd_start; p <= fwd_end; p += 4) {
        integer idx = p - z__; // recover current index
        integer write_offset = idx - (pp << 1) - 2;
        z__[write_offset] = d__ + *(p - 1);

        if (*(p - 1) <= tol2 * d__) {
            *(p - 1) = -0.;
            z__[write_offset] = d__;
            z__[write_offset + 2] = 0.;
            d__ = *(p + 1);
        } else if (safmin * *(p + 1) < z__[write_offset] && safmin * z__[write_offset] < *(p + 1)) {
            temp = *(p + 1) / z__[write_offset];
            z__[write_offset + 2] = *(p - 1) * temp;
            d__ *= temp;
        } else {
            z__[write_offset + 2] = *(p + 1) * (*(p - 1) / z__[write_offset]);
            d__ = *(p + 1) * (d__ / z__[write_offset]);
        }
        d__1 = emin;
        d__2 = z__[write_offset + 2];
        emin = (d__1 <= d__2) ? d__1 : d__2;
    }

    z__[(n0 << 2) - pp - 2] = d__;
    qmax = z__[(i0 << 2) - pp - 2];

    doublereal* q_start = &z__[(i0 << 2) - pp + 2];
    doublereal* q_end = &z__[(n0 << 2) - pp - 2];

    for (doublereal* p = q_start; p <= q_end; p += 4) {
        d__1 = qmax;
        d__2 = *p;
        qmax = (d__1 >= d__2) ? d__1 : d__2;
    }
    pp = 1 - pp;
}
}
