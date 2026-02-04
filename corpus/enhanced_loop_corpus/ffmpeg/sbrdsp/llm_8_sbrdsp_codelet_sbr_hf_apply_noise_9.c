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
for (m = 0; m < m_max; m += 2) {
    float y0_0, y1_0, y0_1, y1_1;
    float noise0, noise1;
    
    // Unroll loop by factor of 2 to increase computational intensity
    if (m + 1 >= m_max) {
        // Handle odd-sized m_max: process only one iteration
        y0_0 = Y[m][0];
        y1_0 = Y[m][1];
        noise0 = (noise + 1) & 511;
        if (s_m[m]) {
            y0_0 += s_m[m] * phi_sign0;
            y1_0 += s_m[m] * phi_sign1;
        } else {
            y0_0 += q_filt[m] * ff_sbr_noise_table[(int)noise0][0];
            y1_0 += q_filt[m] * ff_sbr_noise_table[(int)noise0][1];
        }
        Y[m][0] = y0_0;
        Y[m][1] = y1_0;
        phi_sign1 = -phi_sign1;
        noise = (int)noise0;
    } else {
        // Process two iterations per loop
        y0_0 = Y[m][0];
        y1_0 = Y[m][1];
        y0_1 = Y[m+1][0];
        y1_1 = Y[m+1][1];

        noise0 = (noise + 1) & 511;
        noise1 = (noise + 2) & 511;

        if (s_m[m]) {
            y0_0 += s_m[m] * phi_sign0;
            y1_0 += s_m[m] * phi_sign1;
        } else {
            y0_0 += q_filt[m] * ff_sbr_noise_table[(int)noise0][0];
            y1_0 += q_filt[m] * ff_sbr_noise_table[(int)noise0][1];
        }

        // Update phi_sign1 for next virtual iteration
        float phi_sign1_next = -phi_sign1;
        if (s_m[m+1]) {
            y0_1 += s_m[m+1] * phi_sign0;
            y1_1 += s_m[m+1] * phi_sign1_next;
        } else {
            y0_1 += q_filt[m+1] * ff_sbr_noise_table[(int)noise1][0];
            y1_1 += q_filt[m+1] * ff_sbr_noise_table[(int)noise1][1];
        }

        Y[m][0] = y0_0;
        Y[m][1] = y1_0;
        Y[m+1][0] = y0_1;
        Y[m+1][1] = y1_1;

        phi_sign1 = -phi_sign1_next; // After two flips: -( -phi_sign1 ) => phi_sign1
        noise = (int)noise1;
    }
}
}
