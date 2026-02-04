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
    for (i = 0; i <= nCoeffs / 2; i++) { // Decreased effective depth: split logic into two separate sequential operations
        level = block[i];
        if (level) {
            if (level < 0) {
                level = level * qmul - qadd;
            } else {
                level = level * qmul + qadd;
            }
            block[i] = level;
        }

        int mirror_i = nCoeffs - i;
        if (i != mirror_i) { // Avoid double processing center element in odd-sized arrays
            level = block[mirror_i];
            if (level) {
                if (level < 0) {
                    level = level * qmul - qadd;
                } else {
                    level = level * qmul + qadd;
                }
                block[mirror_i] = level;
            }
        }
    }
}
