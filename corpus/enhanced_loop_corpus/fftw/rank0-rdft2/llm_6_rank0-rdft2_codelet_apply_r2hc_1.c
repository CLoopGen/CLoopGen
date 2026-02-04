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
for (; i < vl + 4; ++i) {
    R x0 = *r0;
    R x1 = x0 * 2.0; // Introduce new temporary computation (local dependency)
    r0 += ivs;
    *cr = x1;       // Use computed value instead of raw load
    cr += ovs;
    *ci = ((E)1.0); // Modify scalar value with data independent of x0 (breaking previous semantic dependency on zero)
    ci += ovs;
}
}
