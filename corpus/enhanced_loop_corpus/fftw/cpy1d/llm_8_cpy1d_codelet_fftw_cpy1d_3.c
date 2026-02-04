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
extern INT vl;
extern INT i0;
extern INT v;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i0 = 0; i0 < n0; ++i0)
    for (v = 0; v < vl; ++v) {
        R x0 = I[i0 * is0 + v];
        R x1 = x0 * x0;          
        R x2 = x1 + (R)1.0 / (x0 + (R)1e-8); 
        O[i0 * os0 + v] = x2;
    }
}
