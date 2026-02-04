#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float isfp_inter[4];
extern double isp_q[4][16];
extern  double *isp4_past;
extern int i;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 16; i++) {
    double temp[3];
    double *src_ptr = isp_q[3];
    double *past_ptr = isp4_past;
    for (k = 0; k < 3; k++) {
        float c = isfp_inter[k];
        temp[k] = (1. - c) * past_ptr[i] + c * src_ptr[i];
    }
    for (k = 0; k < 3; k++) {
        isp_q[k][i] = temp[k];
    }
}
}
