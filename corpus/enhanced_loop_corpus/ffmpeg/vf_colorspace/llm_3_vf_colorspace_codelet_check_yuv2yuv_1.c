#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int n;
extern int16_t (*offset)[8];
extern int16_t (*coeff)[3][8];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access – reverse the iteration and use fixed stride jumps
    // This creates non-consecutive, strided access pattern across each column of the 3D coeff array
    for (n = 7; n >= 0; n--) {
        // Reverse-order access for offset, still writing same values
        offset[0][7 - n] = 16;
        offset[1][7 - n] = 16;

        // Strided access: jump through the third dimension first, but write in reversed index
        const int idx = 7 - n;
        coeff[0][0][idx] = (1 << 14) + (1 << 7) + 1;
        coeff[0][1][idx] = (1 << 7) - 1;
        coeff[0][2][idx] = -(1 << 8);
        coeff[1][0][idx] = 0;
        coeff[2][0][idx] = 0;
        coeff[1][1][idx] = (1 << 14) + (1 << 7);
        coeff[1][2][idx] = -(1 << 7);
        coeff[2][2][idx] = (1 << 14) - (1 << 6);
        coeff[2][1][idx] = 1 << 6;
    }
}
