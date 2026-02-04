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
// Variant 1: Memory Access Pattern Modification - Convert strided access into consecutive-like access using index precomputation
// Instead of repeatedly calculating (i0 << 2) + pp, we precompute base indices and traverse with a local array-like view.
for (k = 1; k <= 2; ++k) {
    integer base_n0 = (n0 << 2) + pp;
    d__ = z__[base_n0 - 3];
    integer start_idx = (i0 << 2) + pp;
    integer end_idx = (n0 - 1 << 2) + pp;

    // First backward pass with precomputed indices stored in a temporary list (simulated via loop with step)
    for (i4 = end_idx; i4 >= start_idx; i4 -= 4) {
        if (z__[i4 - 1] <= tol2 * d__) {
            z__[i4 - 1] = -0.;
            d__ = z__[i4 - 3];
        } else {
            d__ = z__[i4 - 3] * (d__ / (d__ + z__[i4 - 1]));
        }
    }

    emin = z__[(i0 << 2) + pp + 1];
    d__ = z__[(i0 << 2) + pp - 3];
    integer forward_start = (i0 << 2) + pp;
    integer forward_end = (n0 - 1 << 2) + pp;

    // Forward pass with consecutive semantic via offset array simulation
    for (i4 = forward_start; i4 <= forward_end; i4 += 4) {
        integer offset = i4 - (pp << 1) - 2;
        z__[offset] = d__ + z__[i4 - 1];

        if (z__[i4 - 1] <= tol2 * d__) {
            z__[i4 - 1] = -0.;
            z__[offset] = d__;
            z__[offset + 2] = 0.;
            d__ = z__[i4 + 1];
        } else if (safmin * z__[i4 + 1] < z__[offset] && safmin * z__[offset] < z__[i4 + 1]) {
            temp = z__[i4 + 1] / z__[offset];
            z__[offset + 2] = z__[i4 - 1] * temp;
            d__ *= temp;
        } else {
            z__[offset + 2] = z__[i4 + 1] * (z__[i4 - 1] / z__[offset]);
            d__ = z__[i4 + 1] * (d__ / z__[offset]);
        }
        d__1 = emin;
        d__2 = z__[offset + 2];
        emin = (d__1 <= d__2) ? d__1 : d__2;
    }

    z__[(n0 << 2) - pp - 2] = d__;
    qmax = z__[(i0 << 2) - pp - 2];
    integer qstart = (i0 << 2) - pp + 2;
    integer qend = (n0 << 2) - pp - 2;

    for (i4 = qstart; i4 <= qend; i4 += 4) {
        d__1 = qmax;
        d__2 = z__[i4];
        qmax = (d__1 >= d__2) ? d__1 : d__2;
    }
    pp = 1 - pp;
}
}
