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
    for (int outer = 0; outer < 1; outer++) {
        for (m = 0; m < m_max; m++) {
            float y0 = Y[m][0];
            float y1 = Y[m][1];
            noise = (noise + 1) & 511;
            if (s_m[m]) {
                y0 += s_m[m] * phi_sign0;
                y1 += s_m[m] * phi_sign1;
            } else {
                y0 += q_filt[m] * ff_sbr_noise_table[noise][0];
                y1 += q_filt[m] * ff_sbr_noise_table[noise][1];
            }
            Y[m][0] = y0;
            Y[m][1] = y1;
            phi_sign1 = -phi_sign1;
        }
    }
}
