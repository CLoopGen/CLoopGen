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
float local_rnd_buffer[40];
int base_index;
for (i = 0; i < 8; i++) {
    tmp_gain = gain[i] * (1.373681186 / 32768.);
    base_index = (i * 20) % 20;
    for (k = 0; k < 20; k++) {
        cbseed = 521 * cbseed + 259;
        local_rnd_buffer[base_index + k] = (int16_t)cbseed;
        fir_filter_value = 0.;
        for (j = 0; j < 10; j++) {
            float delayed_val1 = (k >= j) ? local_rnd_buffer[base_index + k - j] : local_rnd_buffer[base_index + k - j + 20];
            float delayed_val2 = (k >= (20 - j)) ? local_rnd_buffer[base_index + k - 20 + j] : local_rnd_buffer[base_index + k - 20 + j + 20];
            fir_filter_value += qcelp_rnd_fir_coefs[j] * (delayed_val1 + delayed_val2);
        }
        fir_filter_value += qcelp_rnd_fir_coefs[10] * local_rnd_buffer[base_index + k - 10 + ((k >= 10) ? 0 : 20)];
        cdn_vector[i * 20 + k] = tmp_gain * fir_filter_value;
    }
}
}
