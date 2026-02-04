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
for (k = 2; k < npad / 2; k += 2) {
    E rB1, iB1, rW1, iW1, a1, b1;
    E rB2, iB2, rW2, iW2, a2, b2;

    // First iteration (k)
    rW1 = omega[k];
    iW1 = omega[npad - k];
    rB1 = buf[k];
    iB1 = buf[npad - k];
    a1 = rW1 * rB1 - iW1 * iB1;
    b1 = rW1 * iB1 + iW1 * rB1;
    buf[k] = a1 + b1;
    buf[npad - k] = a1 - b1;

    // Second iteration (k+1), with bounds check
    INT k1 = k + 1;
    if (k1 >= npad / 2) continue;

    rW2 = omega[k1];
    iW2 = omega[npad - k1];
    rB2 = buf[k1];
    iB2 = buf[npad - k1];
    a2 = rW2 * rB2 - iW2 * iB2;
    b2 = rW2 * iB2 + iW2 * rB2;
    buf[k1] = a2 + b2;
    buf[npad - k1] = a2 - b2;
}
}
