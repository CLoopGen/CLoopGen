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
R acc = 0.0;
for (; n0 > 0; --n0 , I += is0 , O += os0) {
    R x0 = I[0];
    R x1 = I[1];
    R x2 = I[2];
    R x3 = I[3];
    acc += x0 + x1 + x2 + x3;
    O[0] = acc;
    O[1] = acc;
    O[2] = acc;
    O[3] = acc;
}
}
