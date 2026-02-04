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
    // Variant 2: Indirect memory access via index remapping
    // Use an auxiliary array to define access order — simulating indirect addressing
    // Here we assume `idxq` contains valid permutation indices in reverse order
    // We traverse elements based on indirect indexing from `idxq`
    integer *indices = idxq + 1; // base pointer to start of index queue
    for (i__ = *nl; i__ >= 1; --i__) {
        integer pos = indices[i__]; // indirect position lookup
        if (pos >= 1 && pos <= *nl) { // validate indirect index
            z__[pos + 1] = *alpha * vl[pos];
            vl[pos] = 0.;
            vf[pos + 1] = vf[pos];
            d__[pos + 1] = d__[pos];
            idxq[pos + 1] = idxq[pos] + 1;
        }
    }
}
