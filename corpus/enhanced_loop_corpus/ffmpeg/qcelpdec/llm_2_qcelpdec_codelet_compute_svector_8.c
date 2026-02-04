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
    // Variant 1: Consecutive memory access with precomputed indices and local array for rnd values
    float rnd_local[30]; // Local buffer to hold recent rnd values for consecutive access
    int idx;

    for (i = 0; i < 8; i++) {
        tmp_gain = gain[i] * (1.373681186 / 32768.);
        for (k = 0; k < 20; k++) {
            cbseed = 521 * cbseed + 259;
            rnd_local[k] = (int16_t)cbseed; // Store in local array consecutively

            fir_filter_value = 0.;
            for (j = 0; j < 10; j++) {
                // Access local buffer with positive indices instead of negative strides
                fir_filter_value += qcelp_rnd_fir_coefs[j] * (rnd_local[k - j] + rnd_local[k - 20 + j]);
            }
            fir_filter_value += qcelp_rnd_fir_coefs[10] * rnd_local[k - 10];
            *cdn_vector++ = tmp_gain * fir_filter_value;
        }
        // Shift the local buffer to retain last 10 values for next block (simulating overlap)
        for (idx = 0; idx < 10; idx++) {
            rnd_local[idx] = rnd_local[idx + 20];
        }
    }
}
