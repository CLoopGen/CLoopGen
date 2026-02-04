#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float INTFLOAT;

extern const INTFLOAT ff_sbr_noise_table[][2];
extern float (*Y)[2];
extern  float *s_m;
extern  float *q_filt;
extern int noise;
extern float phi_sign0;
extern float phi_sign1;
extern int m_max;
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = 0; m < m_max; m++) {
    float y0 = Y[m][0];
    float y1 = Y[m][1];
    noise = (noise + 1) & 511;
    float sign_noise_0 = ff_sbr_noise_table[noise][0];
    float sign_noise_1 = ff_sbr_noise_table[noise][1];
    float input = s_m[m];
    float q_val = q_filt[m];
    y0 += input ? (input * phi_sign0) : (q_val * sign_noise_0);
    y1 += input ? (input * phi_sign1) : (q_val * sign_noise_1);
    Y[m][0] = y0;
    Y[m][1] = y1;
    phi_sign1 = -phi_sign1;
}
}
