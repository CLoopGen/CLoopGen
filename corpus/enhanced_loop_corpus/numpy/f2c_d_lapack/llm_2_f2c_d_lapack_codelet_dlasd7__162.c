#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *nl;
extern doublereal *d__;
extern doublereal *z__;
extern doublereal *vf;
extern doublereal *vl;
extern doublereal *alpha;
extern integer *idxq;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2)
    // Arrays are accessed with a step size of 2, processing every second element
    // Loop direction adjusted to ensure valid indices when stepping by 2
    for (i__ = (*nl % 2 == 1) ? *nl : *nl - 1; i__ >= 1; i__ -= 2) {
        if (i__ + 1 <= *nl + 1) { // bounds check for z__, vf, d__, idxq
            z__[i__ + 1] = *alpha * vl[i__];
            vl[i__] = 0.;
            vf[i__ + 1] = vf[i__];
            d__[i__ + 1] = d__[i__];
            idxq[i__ + 1] = idxq[i__] + 1;
        }
        // Handle next strided index if within bounds
        if (i__ - 1 >= 1 && i__ <= *nl) {
            integer j = i__ - 1;
            if (j + 1 <= *nl + 1) {
                z__[j + 1] = *alpha * vl[j];
                vl[j] = 0.;
                vf[j + 1] = vf[j];
                d__[j + 1] = d__[j];
                idxq[j + 1] = idxq[j] + 1;
            }
        }
    }
}
