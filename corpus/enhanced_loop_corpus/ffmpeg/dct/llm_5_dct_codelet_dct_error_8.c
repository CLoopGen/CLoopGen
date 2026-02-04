#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int64_t sysErr[64];
extern int64_t sysErrMax;
extern int64_t err2_matrix[64];
extern int64_t err2_max;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 64; i++) {
    int64_t posSysErr = sysErr[i];
    int64_t posErr2 = err2_matrix[i];
    posSysErr = (posSysErr >= 0) ? posSysErr : -posSysErr;
    posErr2 = (posErr2 >= 0) ? posErr2 : -posErr2;
    if (posSysErr <= sysErrMax && posErr2 <= err2_max) {
        continue;
    }
    if (posSysErr > sysErrMax) {
        sysErrMax = posSysErr;
    }
    if (posErr2 > err2_max) {
        err2_max = posErr2;
    }
}
}
