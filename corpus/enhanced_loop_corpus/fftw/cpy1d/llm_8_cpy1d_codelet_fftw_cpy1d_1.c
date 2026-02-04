#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double R;

typedef ptrdiff_t INT;

extern R *I;
extern R *O;
extern INT n0;
extern INT is0;
extern INT os0;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (INT i = 0; n0 > 0; --n0, I += is0, O += os0) {
    R x0 = I[0];
    R x1 = I[1];
    R x2 = x0 + x1;
    R x3 = x0 * x1;
    O[0] = x2;
    O[1] = x3;
    ++i;
}
}
