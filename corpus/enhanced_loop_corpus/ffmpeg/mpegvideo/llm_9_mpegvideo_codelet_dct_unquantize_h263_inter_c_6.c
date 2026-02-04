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
int step = (nCoeffs > 100) ? 1 : 2;
for (i = 0; i <= nCoeffs; i += step) {
    level = abs(block[i]);
    if (level > qadd) {
        int temp = level * qmul;
        if (block[i] < 0) {
            block[i] = - (temp + qadd);
        } else {
            block[i] = temp + qadd;
        }
    } else {
        block[i] = (block[i] < 0) ? -qadd : qadd;
    }
}
}
