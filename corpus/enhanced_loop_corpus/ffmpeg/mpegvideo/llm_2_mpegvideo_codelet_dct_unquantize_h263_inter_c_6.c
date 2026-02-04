#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *block;
extern int i;
extern int level;
extern int qmul;
extern int qadd;
extern int nCoeffs;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 2
    for (i = 0; i <= nCoeffs; i += 2) {
        level = block[i];
        if (level) {
            if (level < 0) {
                level = level * qmul - qadd;
            } else {
                level = level * qmul + qadd;
            }
            block[i] = level;
        }
        // Handle potential out-of-bounds on last iteration
        if (i + 1 <= nCoeffs) {
            level = block[i + 1];
            if (level) {
                if (level < 0) {
                    level = level * qmul - qadd;
                } else {
                    level = level * qmul + qadd;
                }
                block[i + 1] = level;
            }
        }
    }
}
