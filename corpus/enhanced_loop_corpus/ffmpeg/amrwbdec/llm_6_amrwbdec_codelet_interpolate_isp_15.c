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
for (k = 0; k < 3; k++) {
    float c = isfp_inter[k];
    double temp[16];
    for (i = 0; i < 16; i++)
        temp[i] = (1. - c) * isp4_past[i] + c * isp_q[3][i];
    for (i = 0; i < 16; i++)
        isp_q[k][i] = temp[i];
}
}
