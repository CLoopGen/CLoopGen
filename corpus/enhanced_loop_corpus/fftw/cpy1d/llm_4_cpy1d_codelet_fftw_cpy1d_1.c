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
INT i = 0;
for (; n0 > 0; --n0, I += is0, O += os0, ++i) {
    R x0 = I[0];
    R x1 = I[1];
    if (i % 2 == 0) {
        O[0] = x0;
        O[1] = x1;
    } else {
        O[0] = x1;
        O[1] = x0;
    }
}
}
