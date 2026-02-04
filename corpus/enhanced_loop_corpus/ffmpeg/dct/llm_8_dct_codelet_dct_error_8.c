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
for (i = 0; i < 64; i += 2) {
    int64_t abs_sysErr_i = (sysErr[i] >= 0) ? sysErr[i] : -sysErr[i];
    int64_t abs_err2_matrix_i = (err2_matrix[i] >= 0) ? err2_matrix[i] : -err2_matrix[i];
    sysErrMax = (sysErrMax > abs_sysErr_i) ? sysErrMax : abs_sysErr_i;
    err2_max = (err2_max > abs_err2_matrix_i) ? err2_max : abs_err2_matrix_i;

    if (i + 1 < 64) {
        int64_t abs_sysErr_i1 = (sysErr[i+1] >= 0) ? sysErr[i+1] : -sysErr[i+1];
        int64_t abs_err2_matrix_i1 = (err2_matrix[i+1] >= 0) ? err2_matrix[i+1] : -err2_matrix[i+1];
        sysErrMax = (sysErrMax > abs_sysErr_i1) ? sysErrMax : abs_sysErr_i1;
        err2_max = (err2_max > abs_err2_matrix_i1) ? err2_max : abs_err2_matrix_i1;
    }
}
}
