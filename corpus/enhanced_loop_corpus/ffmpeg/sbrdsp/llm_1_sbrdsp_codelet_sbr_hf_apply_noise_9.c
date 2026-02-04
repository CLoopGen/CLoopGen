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
    if (m_max > 0) {
        for (m = 0; m < m_max; m += 2) {
            int limit = (m + 1 < m_max) ? m + 2 : m + 1;
            for (int inner = m; inner < limit; inner++) {
                float y0 = Y[inner][0];
                float y1 = Y[inner][1];
                noise = (noise + 1) & 511;
                if (s_m[inner]) {
                    y0 += s_m[inner] * phi_sign0;
                    y1 += s_m[inner] * phi_sign1;
                } else {
                    y0 += q_filt[inner] * ff_sbr_noise_table[noise][0];
                    y1 += q_filt[inner] * ff_sbr_noise_table[noise][1];
                }
                Y[inner][0] = y0;
                Y[inner][1] = y1;
                phi_sign1 = -phi_sign1;
            }
        }
    }
}
