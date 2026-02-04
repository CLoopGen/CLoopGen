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
    R x0 = I[idx_I];
    R x1 = I[idx_I + 2];  // Strided access with stride 2 on input
    O[idx_O] = x1;        // Swap order in output
    O[idx_O + 1] = x0;
}
}
