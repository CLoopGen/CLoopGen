#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double R;

typedef ptrdiff_t INT;

typedef R E;

extern R *r0;
extern R *cr;
extern R *ci;
extern INT i;
extern INT vl;
extern INT ivs;
extern INT ovs;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 8; i <= vl; i += 8) {
    R x0, x1, x2, x3, x4, x5, x6, x7;
    x0 = *r0; r0 += ivs;
    x1 = *r0; r0 += ivs;
    x2 = *r0; r0 += ivs;
    x3 = *r0; r0 += ivs;
    x4 = *r0; r0 += ivs;
    x5 = *r0; r0 += ivs;
    x6 = *r0; r0 += ivs;
    x7 = *r0; r0 += ivs;

    *cr = x0; cr += ovs; *ci = ((E)0.); ci += ovs;
    *cr = x1; cr += ovs; *ci = ((E)0.); ci += ovs;
    *cr = x2; cr += ovs; *ci = ((E)0.); ci += ovs;
    *cr = x3; cr += ovs; *ci = ((E)0.); ci += ovs;
    *cr = x4; cr += ovs; *ci = ((E)0.); ci += ovs;
    *cr = x5; cr += ovs; *ci = ((E)0.); ci += ovs;
    *cr = x6; cr += ovs; *ci = ((E)0.); ci += ovs;
    *cr = x7; cr += ovs; *ci = ((E)0.); ci += ovs;

    // Additional arithmetic to increase computational intensity
    *cr = x0 + x4; cr += ovs; *ci = x1 - x5; ci += ovs;
    *cr = x2 * x6; cr += ovs; *ci = x3 / (x7 + 1e-9); ci += ovs;
}
}
