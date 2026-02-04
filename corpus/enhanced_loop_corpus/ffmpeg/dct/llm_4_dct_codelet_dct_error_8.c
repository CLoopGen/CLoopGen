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
    int64_t absSysErr = sysErr[i];
    int64_t absErr2 = err2_matrix[i];
    if (absSysErr < 0) absSysErr = -absSysErr;
    if (absErr2 < 0) absErr2 = -absErr2;
    if (absSysErr > sysErrMax) sysErrMax = absSysErr;
    if (absErr2 > err2_max) err2_max = absErr2;
}
}
