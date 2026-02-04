#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *quant_energy;
extern int log2_ma_pred_order;
extern int i;
extern int avg_gain;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int outer_i;
    int unroll_factor = 2;
    int start = (1 << log2_ma_pred_order) - 1;
    for (outer_i = start; outer_i > 0; outer_i -= unroll_factor) {
        if (outer_i >= 2) {
            avg_gain += quant_energy[outer_i - 1];
            quant_energy[outer_i] = quant_energy[outer_i - 1];
            avg_gain += quant_energy[outer_i - 2];
            quant_energy[outer_i - 1] = quant_energy[outer_i - 2];
        } else {
            avg_gain += quant_energy[outer_i - 1];
            quant_energy[outer_i] = quant_energy[outer_i - 1];
        }
    }
}
