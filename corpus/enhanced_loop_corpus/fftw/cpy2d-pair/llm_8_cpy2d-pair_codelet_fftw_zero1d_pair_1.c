#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double R;

typedef ptrdiff_t INT;

extern R *O0;
extern R *O1;
extern INT n0;
extern INT os0;
extern INT i0;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i0 = 0; i0 < n0; ++i0) {
    O0[i0 * os0] = 0;
    O1[i0 * os0] = 0;
    O0[i0 * os0] += i0 * 2.5;
    O1[i0 * os0] += (R)(i0 * i0);
}
}
