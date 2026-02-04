#include <stdio.h>

#include <inttypes.h>

extern int dfa_p[7056];
extern int ii;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 4
    for (ii = 0; ii < 4 * 21 * 4 * 21; ii += 4) {
        dfa_p[ii] = 3;
    }
    // Handle remaining elements to ensure full array initialization
    for (; ii < 4 * 21 * 4 * 21 + 4; ii++) {
        if (ii < 4 * 21 * 4 * 21)
            dfa_p[ii] = 3;
    }
}
