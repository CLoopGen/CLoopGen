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



void loop(){
// Variant 2: Reduced computational intensity with modified trip count and simplified arithmetic.
// The loop now runs only over a subset (first half of original range), and redundant computations are removed.
// Also, conditional updates are partially fused.

integer trip_limit = (m - i__1) / 2 + i__1; // Reduce effective trip count to half
for (i__ = m - 1; i__ >= trip_limit; --i__) {
    bb = e[i__];
    r__ = p + bb;
    // Remove conditional check for performance; always assign (safe due to index bounds)
    e[i__ + 1] = s * r__;  // May overwrite but within assumed safe bounds

    c__ = p / r__;         // Skip temp storage: remove oldc usage
    s = bb / r__;
    gamma = c__ * (d__[i__] - sigma) - s * gamma; // Reuse gamma directly, avoid oldgam
    d__[i__ + 1] = gamma + d__[i__];              // Simplified update using redefined gamma

    // Merge branch: use fused expression to avoid branching
    p = (c__ != 0.0) ? (gamma * gamma / c__) : (c__ * bb); // Note: c__==0 implies oldc=0, so p=0
}

// Final cleanup if needed via external logic (assumed handled outside)
}
