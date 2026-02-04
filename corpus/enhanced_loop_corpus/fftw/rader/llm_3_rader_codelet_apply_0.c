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
    for (k = 1; k < r; ++k) {
        E rB, iB, rW, iW;
        INT data_idx = k * os;
        INT omega_idx = 2 * (k - 1);
        rW = omega[omega_idx];
        iW = omega[omega_idx + 1];
        rB = ro[data_idx];
        iB = io[data_idx];
        ro[data_idx] = rW * rB - iW * iB;
        io[data_idx] = -(rW * iB + iW * rB);
    }
}
