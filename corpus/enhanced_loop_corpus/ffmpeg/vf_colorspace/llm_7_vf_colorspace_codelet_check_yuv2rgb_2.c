#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int n;
extern int16_t (*offset);
extern int16_t (*coeff)[3][8];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reverse iteration to alter loop-carried dependence direction (though no actual carry exists, access pattern changes)
    for (n = 7; n >= 0; n--) {
        offset[n] = 16;
        // Introduce artificial WAW and WAR by reordering and repeating writes
        coeff[2][1][n] = 1 << 11;
        coeff[1][2][n] = 1 << 12;
        coeff[1][1][n] = -(1 << 12);
        coeff[0][2][n] = 1 << 13;
        coeff[2][2][n] = 0;
        coeff[0][1][n] = coeff[2][2][n]; // WAR: write after read if ordered differently, but safe here due to reverse
        int16_t temp = (1 << 14) | 1;
        coeff[2][0][n] = temp;
        coeff[1][0][n] = temp;
        coeff[0][0][n] = temp;
    }
}
