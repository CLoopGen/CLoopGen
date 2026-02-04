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
for (i = 0; i < nCoeffs; i += 2) {
    level = block[i];
    if (level) {
        if (level < 0) {
            level = level * qmul - qadd;
        } else {
            level = level * qmul + qadd;
        }
        block[i] = level;
    }
    if (i + 1 < nCoeffs) {
        level = block[i + 1];
        if (level) {
            if (level < 0) {
                level = (level * qmul - qadd) * qmul;
            } else {
                level = (level * qmul + qadd) * qmul;
            }
            block[i + 1] = level;
        }
    }
}
}
