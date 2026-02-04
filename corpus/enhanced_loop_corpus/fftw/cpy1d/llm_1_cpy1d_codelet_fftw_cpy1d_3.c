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
    for (INT offset = 0; offset < vl; ++offset)
        for (v = offset; v < vl && v == offset; ++v) {
            R x0 = I[i0 * is0 + v];
            O[i0 * os0 + v] = x0;
        }
}
