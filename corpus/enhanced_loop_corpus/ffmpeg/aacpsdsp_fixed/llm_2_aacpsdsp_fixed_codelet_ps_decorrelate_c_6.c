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
    for (m = 0; m < 3; m++) {
        int idx = n + 2 - m;
        INTFLOAT a_re = (int)(((int64_t)(ag[m]) * (in_re) + 1073741824) >> 31);
        INTFLOAT a_im = (int)(((int64_t)(ag[m]) * (in_im) + 1073741824) >> 31);
        INTFLOAT link_delay_re = ap_delay[m][idx][0];
        INTFLOAT link_delay_im = ap_delay[m][idx][1];
        INTFLOAT fractional_delay_re = Q_fract[m][0];
        INTFLOAT fractional_delay_im = Q_fract[m][1];
        INTFLOAT apd_re = in_re;
        INTFLOAT apd_im = in_im;
        in_re = (int)((((int64_t)(link_delay_re) * (fractional_delay_re)) - ((int64_t)(link_delay_im) * (fractional_delay_im)) + 536870912) >> 30);
        in_re -= (UINTFLOAT)a_re;
        in_im = (int)((((int64_t)(link_delay_re) * (fractional_delay_im)) + ((int64_t)(link_delay_im) * (fractional_delay_re)) + 536870912) >> 30);
        in_im -= (UINTFLOAT)a_im;
        int store_idx = n + 5;
        ap_delay[m][store_idx][0] = apd_re + (UINTFLOAT)(int)(((int64_t)(ag[m]) * (in_re) + 1073741824) >> 31);
        ap_delay[m][store_idx][1] = apd_im + (UINTFLOAT)(int)(((int64_t)(ag[m]) * (in_im) + 1073741824) >> 31);
    }
    out[n][0] = (int)(((int64_t)(transient_gain[n]) * (in_re) + 32768) >> 16);
    out[n][1] = (int)(((int64_t)(transient_gain[n]) * (in_im) + 32768) >> 16);
}
}
