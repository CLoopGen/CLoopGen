#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *quant_energy;
int log2_ma_pred_order;
int i;
int avg_gain;

void init_vars() {
    log2_ma_pred_order = 20; 
    int array_size = 1 << log2_ma_pred_order; 

    quant_energy = (int16_t*)aligned_alloc(32, array_size * sizeof(int16_t));
    if (!quant_energy) {
        exit(1);
    }

    for (int idx = 0; idx < array_size; idx++) {
        quant_energy[idx] = (int16_t)(idx & 0x7FFF);
    }

    avg_gain = 0;
}