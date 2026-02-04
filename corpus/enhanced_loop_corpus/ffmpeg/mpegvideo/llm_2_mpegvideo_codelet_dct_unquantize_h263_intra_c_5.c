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
    for (i = 1; i <= nCoeffs; i += 2) {
        level = block[i];
        if (level) {
            if (level < 0) {
                level = level * qmul - qadd;
            } else {
                level = level * qmul + qadd;
            }
            block[i] = level;
        }
    }
    // Handle remaining element if nCoeffs is odd
    if (nCoeffs % 2 == 0) return;
    i = nCoeffs;
    level = block[i];
    if (level) {
        if (level < 0) {
            level = level * qmul - qadd;
        } else {
            level = level * qmul + qadd;
        }
        block[i] = level;
    }
}
