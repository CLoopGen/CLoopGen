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
    int16_t temp;
    for (i = 0; i <= nCoeffs; i++) {
        level = block[i];
        if (level) {
            if (level < 0) {
                temp = level * qmul - qadd;
            } else {
                temp = level * qmul + qadd;
            }
            block[i] = temp;
            level = temp; // Introduce WAW dependency: write after write on 'level'
        }
    }
}
