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
    for (INT j = 0; j < 1; ++j) { // Increased loop depth by adding a nested loop
        R x0 = I[j * is0 + 0];
        R x1 = I[j * is0 + 1];
        O[j * os0 + 0] = x0;
        O[j * os0 + 1] = x1;
    }
    I += is0;
    O += os0;
}
}
