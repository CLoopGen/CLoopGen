#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *d__;
extern doublereal *z__;
extern integer i__;
extern doublereal dscale[3];
extern doublereal zscale[3];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via an index mapping array
    // Introduces indirection through a fixed permutation table
    const int indices[3] = {2, 0, 1};  // Custom access order: 2,0,1
    for (i__ = 0; i__ < 3; ++i__) {
        int mapped_index = indices[i__];
        dscale[mapped_index] = d__[mapped_index + 1];
        zscale[mapped_index] = z__[mapped_index + 1];
    }
}
