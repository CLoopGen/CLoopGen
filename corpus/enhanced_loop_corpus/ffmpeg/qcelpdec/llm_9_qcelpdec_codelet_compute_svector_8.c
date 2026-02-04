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
for (i = 0; i < 4; i++) {
    tmp_gain = gain[i] * (0.686840593 / 16384.);
    for (k = 0; k < 40; k++) {
        cbseed = 1563 * cbseed + 777;
        *rnd = (int16_t)cbseed;
        fir_filter_value = 0.;
        for (j = 0; j < 10; j += 2) {
            float term1 = qcelp_rnd_fir_coefs[j] * (rnd[-j] + rnd[-20 + j]);
            float term2 = qcelp_rnd_fir_coefs[j+1] * (rnd[-(j+1)] + rnd[-20 + (j+1)]);
            fir_filter_value += term1 + term2;
        }
        fir_filter_value += qcelp_rnd_fir_coefs[10] * rnd[-10];
        *cdn_vector++ = tmp_gain * fir_filter_value;
        rnd++;
    }
}
}
