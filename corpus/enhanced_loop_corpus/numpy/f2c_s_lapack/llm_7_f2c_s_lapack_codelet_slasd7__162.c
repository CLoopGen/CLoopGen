#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *nl;
extern real *d__;
extern real *z__;
extern real *vf;
extern real *vl;
extern real *alpha;
extern integer *idxq;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
real temp_alpha = *alpha;
integer offset = 1;
for (i__ = *nl; i__ >= 1; --i__) {
    integer curr_idx = i__;
    integer next_idx = i__ + offset;
    z__[next_idx] = temp_alpha * vl[curr_idx];
    vl[curr_idx] = 0.F;
    if (i__ == *nl) {
        vf[next_idx] = vf[curr_idx];
    } else {
        vf[next_idx] = vf[curr_idx + 1]; // Introduce WAR dependency: vf[i+1] now depends on later iteration's vf[i+2]
    }
    d__[next_idx] = d__[curr_idx];
    idxq[next_idx] = idxq[curr_idx] + offset;
}
}
