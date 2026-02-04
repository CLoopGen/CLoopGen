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
    for (k = 0; k < r - 1; ++k) {
        E rB, iB, rW, iW;
        INT idx_omega = 2 * k;
        INT idx_data = (k + 1) * os;
        rW = omega[idx_omega];
        iW = omega[idx_omega + 1];
        rB = ro[idx_data];
        iB = io[idx_data];
        ro[idx_data] = rW * rB - iW * iB;
        io[idx_data] = -(rW * iB + iW * rB);
    }
}
