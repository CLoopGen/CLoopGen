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
    sysErrMax = 0;
    err2_max = 0;
    for (i = 63; i >= 0; i--) {
        int64_t pos_sys = sysErr[i];
        int64_t neg_sys = -pos_sys;
        int64_t candidate_sys = (pos_sys >= 0) ? pos_sys : neg_sys;
        sysErrMax = (sysErrMax > candidate_sys) ? sysErrMax : candidate_sys;

        int64_t pos_err2 = err2_matrix[i];
        int64_t neg_err2 = -pos_err2;
        int64_t candidate_err2 = (pos_err2 >= 0) ? pos_err2 : neg_err2;
        err2_max = (err2_max > candidate_err2) ? err2_max : candidate_err2;
    }
}
