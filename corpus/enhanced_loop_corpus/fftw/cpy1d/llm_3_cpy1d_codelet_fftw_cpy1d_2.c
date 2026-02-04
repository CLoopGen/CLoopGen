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
for (INT i = 0; i < n0; ++i) {
    INT idx_I = i * is0;
    INT idx_O = i * os0;
    R x0 = I[idx_I + 0];
    R x1 = I[idx_I + 1];
    R x2 = I[idx_I + 2];
    R x3 = I[idx_I + 3];
    O[idx_O + 0] = x0;
    O[idx_O + 1] = x1;
    O[idx_O + 2] = x2;
    O[idx_O + 3] = x3;
}
}
