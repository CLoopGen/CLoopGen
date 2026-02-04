#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *d__;
extern real *z__;
extern integer i__;
extern real dscale[3];
extern real sclfac;
extern real zscale[3];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access (stride of 2) with index remapping (simulated via arithmetic)
    // Note: Since array size is 3, we simulate strided access by visiting indices in non-sequential order
    // Using fixed index sequence: 1, 3, 2 to demonstrate non-consecutive pattern
    int indices[] = {1, 3, 2};
    for (i__ = 0; i__ < 3; ++i__) {
        int idx = indices[i__];
        dscale[i__] = d__[idx] * sclfac;
        zscale[i__] = z__[idx] * sclfac;
    }
}
