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
for (i = 1; i <= nCoeffs; i++) {
    level = block[i];
    if (level == 0) {
        // Skip processing if level is zero, no change to block[i]
    } else if (level < 0) {
        block[i] = level * qmul - qadd;
    } else {
        block[i] = level * qmul + qadd;
    }
}
}
