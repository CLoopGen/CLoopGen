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
    for (j4 = (*i0 << 2) + 2; j4 <= i__1; j4 += 4) {
        doublereal sum = d__ + z__[j4 - 1];
        z__[j4 - 2] = sum;

        if (sum == 0.0) {
            z__[j4] = 0.0;
            d__ = z__[j4 + 1];
            *dmin__ = d__;
            emin = 0.0;
        } else {
            doublereal inv_sum = 1.0 / sum;
            doublereal factor = z__[j4 + 1] * inv_sum;

            if (safmin * z__[j4 + 1] < sum && safmin * sum < z__[j4 + 1]) {
                z__[j4] = z__[j4 - 1] * factor;
                d__ *= factor;
            } else {
                z__[j4] = z__[j4 + 1] * (z__[j4 - 1] * inv_sum);
                d__ = z__[j4 + 1] * (d__ * inv_sum);
            }
        }

        if (d__ < *dmin__) {
            *dmin__ = d__;
        }
        if (z__[j4] < emin) {
            emin = z__[j4];
        }
    }
}
