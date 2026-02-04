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
for (INT i = 0; i < n0 && n0 > 1; ++i, I += 2*is0, O += 2*os0) {
    R x0 = I[0];
    R x1 = I[1];
    R x2 = I[is0];
    R x3 = I[is0+1];
    O[0] = x0;
    O[1] = x1;
    O[os0] = x2;
    O[os0+1] = x3;
    --n0;
}
}
