#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double qcelp_rnd_fir_coefs[11];
extern  float *gain;
extern float *cdn_vector;
extern int i;
extern int j;
extern int k;
extern uint16_t cbseed;
extern float *rnd;
extern float tmp_gain;
extern float fir_filter_value;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i++) {
    tmp_gain = gain[i] * (1.373681186 / 32768.);
    for (k = 0; k < 20; k++) {
        cbseed = 521 * cbseed + 259;
        *rnd = (int16_t)cbseed;
        fir_filter_value = 0.;
        if (k >= 10) {
            for (j = 0; j < 10; j++)
                fir_filter_value += qcelp_rnd_fir_coefs[j] * rnd[-j];
            fir_filter_value += qcelp_rnd_fir_coefs[10] * rnd[-10];
        } else {
            for (j = 0; j < 10; j++)
                fir_filter_value += qcelp_rnd_fir_coefs[j] * rnd[-20 + j];
            fir_filter_value += qcelp_rnd_fir_coefs[10] * rnd[-10];
        }
        *cdn_vector++ = tmp_gain * fir_filter_value;
        rnd++;
    }
}
}
