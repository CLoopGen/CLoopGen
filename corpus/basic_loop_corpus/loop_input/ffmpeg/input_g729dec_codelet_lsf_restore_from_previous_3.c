#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t cb_ma_predictor[2][4][10];
int16_t cb_ma_predictor_sum_inv[2][10];
int16_t *lsfq;
int16_t *past_quantizer_outputs[5];
int ma_predictor_prev;
int16_t *quantizer_output;
int i;
int k;

void init_vars() {
    // Allocate lsfq and quantizer_output arrays of size 10
    lsfq = (int16_t*)calloc(10, sizeof(int16_t));
    quantizer_output = (int16_t*)calloc(10, sizeof(int16_t));

    // Allocate each past_quantizer_outputs[k] array
    for (int idx = 0; idx < 5; idx++) {
        past_quantizer_outputs[idx] = (int16_t*)calloc(10, sizeof(int16_t));
    }

    // Initialize cb_ma_predictor with non-zero values to ensure meaningful computation
    for (int a = 0; a < 2; a++) {
        for (int b = 0; b < 4; b++) {
            for (int c = 0; c < 10; c++) {
                cb_ma_predictor[a][b][c] = (a + b + c) % 32 - 16; // Range: -16 to 15
            }
        }
    }

    // Initialize cb_ma_predictor_sum_inv
    for (int a = 0; a < 2; a++) {
        for (int c = 0; c < 10; c++) {
            cb_ma_predictor_sum_inv[a][c] = 1 << 12; // Identity scale when >> 12
        }
    }

    // Initialize lsfq with sample data
    for (int c = 0; c < 10; c++) {
        lsfq[c] = (c + 1) * 1000;
    }

    // Initialize past_quantizer_outputs with some prediction residuals
    for (int idx = 0; idx < 5; idx++) {
        for (int c = 0; c < 10; c++) {
            past_quantizer_outputs[idx][c] = (idx * c) % 17 - 8;
        }
    }

    // Set ma_predictor_prev to valid index: 0 or 1
    ma_predictor_prev = 1;

    // Ensure all variables used as loop counters are initialized
    i = 0;
    k = 0;
}