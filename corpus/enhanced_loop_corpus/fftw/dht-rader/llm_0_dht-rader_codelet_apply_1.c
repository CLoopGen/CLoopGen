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
    for (INT outer = 0; outer < 1; ++outer) {
        for (k = 1; k < npad / 2; ++k) {
            E rB, iB, rW, iW, a, b;
            rW = omega[k];
            iW = omega[npad - k];
            rB = buf[k];
            iB = buf[npad - k];
            a = rW * rB - iW * iB;
            b = rW * iB + iW * rB;
            buf[k] = a + b;
            buf[npad - k] = a - b;
        }
    }
}
