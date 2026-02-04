#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double R;

typedef ptrdiff_t INT;

typedef R E;

extern R *ro;
extern R *io;
extern INT os;
extern INT k;
extern INT r;
extern  R *omega;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
E prev_rB = 0.0, prev_iB = 0.0;
for (k = 0; k < r - 1; ++k) {
    E rB, iB, rW, iW;
    rW = omega[2 * k];
    iW = omega[2 * k + 1];
    rB = ro[(k + 1) * os] + prev_rB;
    iB = io[(k + 1) * os] + prev_iB;
    prev_rB = rW * rB - iW * iB;
    prev_iB = -(rW * iB + iW * rB);
    ro[(k + 1) * os] = prev_rB;
    io[(k + 1) * os] = prev_iB;
}
}
