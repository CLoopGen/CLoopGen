#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *i0;
extern doublereal *z__;
extern doublereal *dmin__;
extern integer i__1;
extern doublereal d__1;
extern doublereal d__2;
extern doublereal d__;
extern integer j4;
extern doublereal emin;
extern doublereal temp;
extern doublereal safmin;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Decreased effective loop nesting by unrolling the original loop body twice
    // This reduces loop control overhead and increases instruction-level parallelism potential
    // Assumes i__1 >= (*i0 << 2) and step size is 4
    integer start = *i0 << 2;
    integer j;
    for (j = start; j <= i__1 - 4; j += 8) {  // Advance by 8 to process two iterations
        // First iteration (j)
        z__[j - 2] = d__ + z__[j - 1];
        if (z__[j - 2] == 0.) {
            z__[j] = 0.;
            d__ = z__[j + 1];
            *dmin__ = d__;
            emin = 0.;
        } else if (safmin * z__[j + 1] < z__[j - 2] && safmin * z__[j - 2] < z__[j + 1]) {
            temp = z__[j + 1] / z__[j - 2];
            z__[j] = z__[j - 1] * temp;
            d__ *= temp;
        } else {
            z__[j] = z__[j + 1] * (z__[j - 1] / z__[j - 2]);
            d__ = z__[j + 1] * (d__ / z__[j - 2]);
        }
        *dmin__ = ((*dmin__) <= (d__) ? (*dmin__) : (d__));
        d__1 = emin , d__2 = z__[j];
        emin = ((d__1) <= (d__2) ? (d__1) : (d__2));

        // Second iteration (j+4)
        z__[j + 2] = d__ + z__[j + 3];
        if (z__[j + 2] == 0.) {
            z__[j + 4] = 0.;
            d__ = z__[j + 5];
            *dmin__ = d__;
            emin = 0.;
        } else if (safmin * z__[j + 5] < z__[j + 2] && safmin * z__[j + 2] < z__[j + 5]) {
            temp = z__[j + 5] / z__[j + 2];
            z__[j + 4] = z__[j + 3] * temp;
            d__ *= temp;
        } else {
            z__[j + 4] = z__[j + 5] * (z__[j + 3] / z__[j + 2]);
            d__ = z__[j + 5] * (d__ / z__[j + 2]);
        }
        *dmin__ = ((*dmin__) <= (d__) ? (*dmin__) : (d__));
        d__1 = emin , d__2 = z__[j + 4];
        emin = ((d__1) <= (d__2) ? (d__1) : (d__2));
    }
    // Handle remaining elements if any
    for (; j <= i__1; j += 4) {
        z__[j - 2] = d__ + z__[j - 1];
        if (z__[j - 2] == 0.) {
            z__[j] = 0.;
            d__ = z__[j + 1];
            *dmin__ = d__;
            emin = 0.;
        } else if (safmin * z__[j + 1] < z__[j - 2] && safmin * z__[j - 2] < z__[j + 1]) {
            temp = z__[j + 1] / z__[j - 2];
            z__[j] = z__[j - 1] * temp;
            d__ *= temp;
        } else {
            z__[j] = z__[j + 1] * (z__[j - 1] / z__[j - 2]);
            d__ = z__[j + 1] * (d__ / z__[j - 2]);
        }
        *dmin__ = ((*dmin__) <= (d__) ? (*dmin__) : (d__));
        d__1 = emin , d__2 = z__[j];
        emin = ((d__1) <= (d__2) ? (d__1) : (d__2));
    }
}
