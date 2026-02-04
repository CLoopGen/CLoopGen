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
// Reduce trip count by half and unroll loop to process two iterations at once
INT step;
for (k = 0; k < (r - 1) / 2; ++k) {
    step = (k + 1) * os;
    E rB1, iB1, rW1, iW1;
    E rB2, iB2, rW2, iW2;

    rW1 = omega[2 * k];
    iW1 = omega[2 * k + 1];
    rB1 = ro[step];
    iB1 = io[step];
    ro[step] = rW1 * rB1 - iW1 * iB1;
    io[step] = -(rW1 * iB1 + iW1 * rB1);

    if ((k + 1) * 2 < r - 1) {  // Safe access for second iteration
        INT step2 = (k + 2) * os;
        rW2 = omega[2 * (k + 1)];
        iW2 = omega[2 * (k + 1) + 1];
        rB2 = ro[step2];
        iB2 = io[step2];
        ro[step2] = rW2 * rB2 - iW2 * iB2;
        io[step2] = -(rW2 * iB2 + iW2 * rB2);
    }
}
}
