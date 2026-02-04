#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int mr_energy;
int16_t *quant_energy;
int16_t *ma_prediction_coeff;
int ma_pred_order;
int i;

void init_vars() {
    ma_pred_order = 131072;  // Approximately 0.01 seconds of work with reasonable access pattern

    quant_energy = (int16_t*)aligned_alloc(32, ma_pred_order * sizeof(int16_t));
    ma_prediction_coeff = (int16_t*)aligned_alloc(32, ma_pred_order * sizeof(int16_t));

    if (!quant_energy || !ma_prediction_coeff) {
        exit(1);
    }

    for (i = 0; i < ma_pred_order; i++) {
        quant_energy[i] = (int16_t)(i % 32768);
        ma_prediction_coeff[i] = (int16_t)((i + 16) % 32768);
    }

    mr_energy = 0;
}