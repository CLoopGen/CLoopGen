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
    for (i = 1; i <= nCoeffs; i += 2) {
        for (int j = 0; j < 2 && (i + j) <= nCoeffs; j++) {
            int idx = i + j;
            level = block[idx];
            if (level) {
                if (level < 0) {
                    level = level * qmul - qadd;
                } else {
                    level = level * qmul + qadd;
                }
                block[idx] = level;
            }
        }
    }
}
