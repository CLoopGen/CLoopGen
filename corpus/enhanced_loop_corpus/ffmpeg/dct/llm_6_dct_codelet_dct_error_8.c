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
    int j;
    for (j = 0; j < 64; j++) {
        int64_t abs_sysErr = (sysErr[j] >= 0) ? sysErr[j] : -sysErr[j];
        int64_t abs_err2 = (err2_matrix[j] >= 0) ? err2_matrix[j] : -err2_matrix[j];
        if (abs_sysErr > sysErrMax) {
            sysErrMax = abs_sysErr;
        }
        if (abs_err2 > err2_max) {
            err2_max = abs_err2;
        }
    }
}
