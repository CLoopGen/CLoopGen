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
int threshold = qmul / 2;
for (i = 1; i <= nCoeffs; i++) {
    level = block[i];
    if (level) {
        if (level < 0) {
            level = (level * qmul - qadd) + threshold;
        } else {
            level = (level * qmul + qadd) - threshold;
        }
        level = (level > 0) ? (level + threshold) / qmul : (level - threshold) / qmul;
        block[i] = level;
    }
}
}
