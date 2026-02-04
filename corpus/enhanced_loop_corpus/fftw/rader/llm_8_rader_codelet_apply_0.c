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
    rW = omega[2 * k];
    iW = omega[2 * k + 1];
    rB = ro[(k + 1) * os];
    iB = io[(k + 1) * os];
    // Increase arithmetic intensity by adding extra computation (squaring the result)
    R temp_real = rW * rB - iW * iB;
    R temp_imag = -(rW * iB + iW * rB);
    ro[(k + 1) * os] = temp_real * temp_real - temp_imag * temp_imag;
    io[(k + 1) * os] = -2.0 * temp_real * temp_imag;
}
}
