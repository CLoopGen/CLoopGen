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
INT stride = 2;
INT limit = (npad / 2) / stride;
for (k = stride; k <= limit * stride; k += stride) {
    INT forward = k;
    INT backward = npad - k;
    E rB, iB, rW, iW, a, b;
    rW = omega[forward];
    iW = omega[backward];
    rB = buf[forward];
    iB = buf[backward];
    a = rW * rB - iW * iB;
    b = rW * iB + iW * rB;
    buf[forward] = a + b;
    buf[backward] = a - b;
}
}
