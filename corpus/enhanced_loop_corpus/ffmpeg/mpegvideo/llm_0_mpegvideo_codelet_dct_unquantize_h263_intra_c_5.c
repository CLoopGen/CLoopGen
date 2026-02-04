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
    for (int outer = 0; outer < 1; outer++) {
        for (i = 1; i <= nCoeffs; i++) {
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
    }
}
