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
int indices[64];
for (int j = 0; j < 64; j++) {
    indices[j] = j;
}
for (int j = 0; j < 64; j++) {
    int idx = indices[j];
    sysErrMax = ((sysErrMax) > (((sysErr[idx]) >= 0 ? (sysErr[idx]) : (-(sysErr[idx])))) ? (sysErrMax) : (((sysErr[idx]) >= 0 ? (sysErr[idx]) : (-(sysErr[idx])))));
    err2_max = ((err2_max) > (((err2_matrix[idx]) >= 0 ? (err2_matrix[idx]) : (-(err2_matrix[idx])))) ? (err2_max) : (((err2_matrix[idx]) >= 0 ? (err2_matrix[idx]) : (-(err2_matrix[idx])))));
}
}
