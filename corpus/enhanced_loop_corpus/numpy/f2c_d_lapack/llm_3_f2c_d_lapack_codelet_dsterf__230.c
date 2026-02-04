#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *d__;
extern doublereal *e;
extern integer i__1;
extern doublereal c__;
extern integer i__;
extern integer m;
extern doublereal p;
extern doublereal r__;
extern doublereal s;
extern doublereal bb;
extern doublereal oldc;
extern doublereal gamma;
extern doublereal alpha;
extern doublereal sigma;
extern doublereal oldgam;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Consecutive Access via Temporary Arrays (improve spatial locality using local buffers)
    doublereal temp_e[64];   // Local cache for e values (assumes m-i__1 <= 64 for safety)
    doublereal temp_d[64];   // Local cache for d values
    integer len = m - i__1;
    if (len > 64) len = 64; // Clamp to buffer size

    // Preload data into temporary arrays with consecutive access
    for (integer j = 0; j < len; ++j) {
        temp_e[j] = e[m - 1 - j];
        temp_d[j] = d__[m - 1 - j];
    }

    // Operate on temporary arrays with forward consecutive access
    for (integer j = 0; j < len; ++j) {
        i__ = m - 1 - j;  // Map back to original index
        bb = temp_e[j];
        r__ = p + bb;
        if (j != 0) {
            e[i__ + 1] = s * r__;  // Write back to original array
        }
        oldc = c__;
        c__ = p / r__;
        s = bb / r__;
        oldgam = gamma;
        alpha = temp_d[j];
        gamma = c__ * (alpha - sigma) - s * oldgam;
        d__[i__ + 1] = oldgam + (alpha - gamma);
        if (c__ != 0.) {
            p = gamma * gamma / c__;
        } else {
            p = oldc * bb;
        }
    }
}
