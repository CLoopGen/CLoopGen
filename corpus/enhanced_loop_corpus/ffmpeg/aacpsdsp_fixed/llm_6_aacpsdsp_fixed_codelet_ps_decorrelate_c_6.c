#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int INTFLOAT;

typedef unsigned int UINTFLOAT;

extern INTFLOAT (*out)[2];
extern INTFLOAT (*delay)[2];
extern INTFLOAT (*ap_delay)[37][2];
extern  INTFLOAT phi_fract[2];
extern  INTFLOAT (*Q_fract)[2];
extern  INTFLOAT *transient_gain;
extern int len;
extern INTFLOAT ag[3];
extern int m;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (n = 0; n < len; n++) {
    INTFLOAT in_re = (int)((((int64_t)(delay[n][0]) * (phi_fract[0])) - ((int64_t)(delay[n][1]) * (phi_fract[1])) + 536870912) >> 30);
    INTFLOAT in_im = (int)((((int64_t)(delay[n][0]) * (phi_fract[1])) + ((int64_t)(delay[n][1]) * (phi_fract[0])) + 536870912) >> 30);
    INTFLOAT temp_re[3], temp_im[3];
    for (m = 0; m < 3; m++) {
        INTFLOAT a_re = (int)(((int64_t)(ag[m]) * (in_re) + 1073741824) >> 31);
        INTFLOAT a_im = (int)(((int64_t)(ag[m]) * (in_im) + 1073741824) >> 31);
        INTFLOAT link_delay_re = ap_delay[m][n + 2 - m][0];
        INTFLOAT link_delay_im = ap_delay[m][n + 2 - m][1];
        INTFLOAT fractional_delay_re = Q_fract[m][0];
        INTFLOAT fractional_delay_im = Q_fract[m][1];
        INTFLOAT apd_re = in_re;
        INTFLOAT apd_im = in_im;
        INTFLOAT new_re = (int)((((int64_t)(link_delay_re) * (fractional_delay_re)) - ((int64_t)(link_delay_im) * (fractional_delay_im)) + 536870912) >> 30);
        INTFLOAT new_im = (int)((((int64_t)(link_delay_re) * (fractional_delay_im)) + ((int64_t)(link_delay_im) * (fractional_delay_re)) + 536870912) >> 30);
        new_re -= (UINTFLOAT)a_re;
        new_im -= (UINTFLOAT)a_im;
        temp_re[m] = apd_re + (UINTFLOAT)(int)(((int64_t)(ag[m]) * (new_re) + 1073741824) >> 31);
        temp_im[m] = apd_im + (UINTFLOAT)(int)(((int64_t)(ag[m]) * (new_im) + 1073741824) >> 31);
        in_re = new_re;
        in_im = new_im;
    }
    for (m = 0; m < 3; m++) {
        ap_delay[m][n + 5][0] = temp_re[m];
        ap_delay[m][n + 5][1] = temp_im[m];
    }
    out[n][0] = (int)(((int64_t)(transient_gain[n]) * (in_re) + 32768) >> 16);
    out[n][1] = (int)(((int64_t)(transient_gain[n]) * (in_im) + 32768) >> 16);
}
}
