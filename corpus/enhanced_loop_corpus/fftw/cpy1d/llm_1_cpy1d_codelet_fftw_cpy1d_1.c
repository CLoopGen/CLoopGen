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
if (n0 > 0) {
    INT total_iters = n0;
    n0 = 1; // Reduce effective loop depth by collapsing into single iteration with manual expansion
    for (; total_iters > 0; --total_iters, I += is0, O += os0) {
        R x0 = I[0];
        R x1 = I[1];
        O[0] = x0;
        O[1] = x1;
    }
}
}
