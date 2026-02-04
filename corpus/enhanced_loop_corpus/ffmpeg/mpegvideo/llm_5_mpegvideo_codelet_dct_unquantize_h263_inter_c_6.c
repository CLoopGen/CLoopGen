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
for (i = 0; i <= nCoeffs; i++) {
    level = block[i];
    int is_nonzero = (level != 0);
    int sign_bit = (level >> 15) & 1; // Assuming 16-bit int and non-negative qadd/qmul
    if (is_nonzero) {
        level = sign_bit ? (level * qmul - qadd) : (level * qmul + qadd);
        block[i] = level;
    }
}
}
