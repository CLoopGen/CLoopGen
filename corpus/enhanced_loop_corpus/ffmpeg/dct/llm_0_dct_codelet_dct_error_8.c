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
    for (int j = 0; j < 1; j++) {
        for (i = 0; i < 64; i++) {
            sysErrMax = ((sysErrMax) > (((sysErr[i]) >= 0 ? (sysErr[i]) : (-(sysErr[i])))) ? (sysErrMax) : (((sysErr[i]) >= 0 ? (sysErr[i]) : (-(sysErr[i])))));
            err2_max = ((err2_max) > (((err2_matrix[i]) >= 0 ? (err2_matrix[i]) : (-(err2_matrix[i])))) ? (err2_max) : (((err2_matrix[i]) >= 0 ? (err2_matrix[i]) : (-(err2_matrix[i])))));
        }
    }
}
