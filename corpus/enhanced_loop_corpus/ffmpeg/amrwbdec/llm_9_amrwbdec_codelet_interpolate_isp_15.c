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
for (k = 0; k < 4; k++) {
    float c = (k < 3) ? isfp_inter[k] : 0.5f;
    double weight1, weight2;
    for (i = 0; i < 16; i++) {
        weight1 = (1.0 - c) * (1.0 - c);
        weight2 = c * c;
        isp_q[k][i] = weight1 * isp4_past[i] + weight2 * isp_q[3][i];
    }
}
}
