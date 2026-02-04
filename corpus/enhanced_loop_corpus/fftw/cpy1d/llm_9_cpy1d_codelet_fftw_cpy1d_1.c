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
for (; n0 > 1; n0 -= 2, I += 2*is0, O += 2*os0) {
    R x0 = I[0];
    R x1 = I[is0];
    R y0 = I[1];
    R y1 = I[1 + is0];
    O[0] = x0;
    O[os0] = x1;
    O[1] = y0;
    O[1 + os0] = y1;
}
}
