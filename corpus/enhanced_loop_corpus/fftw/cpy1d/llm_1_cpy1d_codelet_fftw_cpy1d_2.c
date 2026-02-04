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
for (INT outer = 0; outer < n0; ++outer) {
    for (INT inner = 0; inner < 1; ++inner) {
        R x0 = I[0];
        R x1 = I[1];
        R x2 = I[2];
        R x3 = I[3];
        O[0] = x0;
        O[1] = x1;
        O[2] = x2;
        O[3] = x3;
    }
    I += is0;
    O += os0;
}
}
