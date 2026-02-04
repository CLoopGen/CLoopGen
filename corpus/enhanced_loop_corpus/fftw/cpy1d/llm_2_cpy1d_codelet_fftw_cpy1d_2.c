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
for (INT i = 0; i < n0; ++i, I += is0, O += os0) {
    R x0 = I[0 * is0];
    R x1 = I[1 * is0];
    R x2 = I[2 * is0];
    R x3 = I[3 * is0];
    O[0 * os0] = x0;
    O[1 * os0] = x1;
    O[2 * os0] = x2;
    O[3 * os0] = x3;
}
}
