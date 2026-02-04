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
    int idx = i;
    sysErrMax = ((sysErrMax) > (((sysErr[idx]) >= 0 ? (sysErr[idx]) : (-(sysErr[idx])))) ? (sysErrMax) : (((sysErr[idx]) >= 0 ? (sysErr[idx]) : (-(sysErr[idx])))));
    err2_max = ((err2_max) > (((err2_matrix[idx]) >= 0 ? (err2_matrix[idx]) : (-(err2_matrix[idx])))) ? (err2_max) : (((err2_matrix[idx]) >= 0 ? (err2_matrix[idx]) : (-(err2_matrix[idx])))));
}
for (i = 1; i < 64; i += 2) {
    int idx = i;
    sysErrMax = ((sysErrMax) > (((sysErr[idx]) >= 0 ? (sysErr[idx]) : (-(sysErr[idx])))) ? (sysErrMax) : (((sysErr[idx]) >= 0 ? (sysErr[idx]) : (-(sysErr[idx])))));
    err2_max = ((err2_max) > (((err2_matrix[idx]) >= 0 ? (err2_matrix[idx]) : (-(err2_matrix[idx])))) ? (err2_max) : (((err2_matrix[idx]) >= 0 ? (err2_matrix[idx]) : (-(err2_matrix[idx])))));
}
}
