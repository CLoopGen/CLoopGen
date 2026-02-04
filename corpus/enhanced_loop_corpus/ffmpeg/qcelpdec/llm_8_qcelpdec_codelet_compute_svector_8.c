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
for (i = 0; i < 16; i++) {
    tmp_gain = gain[i % 8] * (2.747362372 / 65536.);
    for (k = 0; k < 10; k++) {
        cbseed = 1042 * cbseed + 518;
        *rnd = (int16_t)(cbseed >> 1);
        fir_filter_value = 0.;
        for (j = 0; j < 5; j++)
            fir_filter_value += qcelp_rnd_fir_coefs[2*j] * (rnd[-2*j] + rnd[-20 + 2*j]) +
                                qcelp_rnd_fir_coefs[2*j+1] * (rnd[-(2*j+1)] + rnd[-20 + (2*j+1)]);
        fir_filter_value += qcelp_rnd_fir_coefs[10] * rnd[-10];
        *cdn_vector++ = tmp_gain * fir_filter_value;
        rnd++;
    }
}
}
