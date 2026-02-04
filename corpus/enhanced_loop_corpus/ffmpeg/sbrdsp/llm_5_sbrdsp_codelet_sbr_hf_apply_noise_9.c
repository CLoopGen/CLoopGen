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
    float temp_y0, temp_y1;
    if (!s_m[m]) {
        temp_y0 = q_filt[m] * ff_sbr_noise_table[noise][0];
        temp_y1 = q_filt[m] * ff_sbr_noise_table[noise][1];
        y0 += temp_y0;
        y1 += temp_y1;
    } else {
        y0 += s_m[m] * phi_sign0;
        y1 += s_m[m] * phi_sign1;
        goto update_output;
    }
    // Additional control divergence: only flip phi_sign1 when s_m[m] is zero
    // This introduces a control-dependent update
    continue;
update_output:
    Y[m][0] = y0;
    Y[m][1] = y1;
    phi_sign1 = -phi_sign1;
}
}
