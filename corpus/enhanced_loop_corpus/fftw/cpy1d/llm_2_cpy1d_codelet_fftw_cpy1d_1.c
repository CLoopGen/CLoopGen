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
    R x0 = I[i * is0];
    R x1 = I[i * is0 + 1];
    O[i * os0] = x0;
    O[i * os0 + 1] = x1;
}
}
