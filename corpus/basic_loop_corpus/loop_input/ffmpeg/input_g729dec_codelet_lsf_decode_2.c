#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t cb_ma_predictor[2][4][10];
int16_t cb_ma_predictor_sum[2][10];
int16_t *lsfq;
int16_t *past_quantizer_outputs[5];
int16_t ma_predictor;
int i;
int j;
int16_t *quantizer_output;

void init_vars() {
    // Allocate lsfq and quantizer_output arrays of size 10
    lsfq = (int16_t*)calloc(10, sizeof(int16_t));
    quantizer_output = (int16_t*)malloc(10 * sizeof(int16_t));

    // Initialize quantizer_output with non-zero values for meaningful computation
    for (int idx = 0; idx < 10; idx++) {
        quantizer_output[idx] = (idx + 1) * 1000;
    }

    // Allocate and initialize past_quantizer_outputs[0..4], each pointing to array of 10 int16_t
    for (int p = 0; p < 5; p++) {
        past_quantizer_outputs[p] = (int16_t*)malloc(10 * sizeof(int16_t));
        for (int idx = 0; idx < 10; idx++) {
            past_quantizer_outputs[p][idx] = (p + 1) * (idx + 1) * 500;
        }
    }

    // Initialize cb_ma_predictor and cb_ma_predictor_sum with sample values
    for (int m = 0; m < 2; m++) {
        for (int idx = 0; idx < 10; idx++) {
            cb_ma_predictor_sum[m][idx] = (m + 1) * (idx + 1) * 2000;
            for (int j = 0; j < 4; j++) {
                cb_ma_predictor[m][j][idx] = (m + 1) * (j + 1) * (idx + 1) * 100;
            }
        }
    }

    // Set ma_predictor within valid range [0,1]
    ma_predictor = 1;
}