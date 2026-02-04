#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef R E;

extern INT npad;
extern INT k;
extern R *buf;
extern R *omega;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 1; k < npad / 2; ++k) {
    INT idx1 = k;
    INT idx2 = npad - k;
    E rB, iB, rW, iW, a, b;
    rW = omega[idx1];
    iW = omega[idx2];
    rB = buf[idx1];
    iB = buf[idx2];
    a = rW * rB - iW * iB;
    b = rW * iB + iW * rB;
    buf[idx1] = a + b;
    buf[idx2] = a - b;
}
}
