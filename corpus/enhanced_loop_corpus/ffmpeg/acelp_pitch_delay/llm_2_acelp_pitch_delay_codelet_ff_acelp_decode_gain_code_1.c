#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int mr_energy;
extern  int16_t *quant_energy;
extern  int16_t *ma_prediction_coeff;
extern int ma_pred_order;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2, unrolled by factor 2)
    int limit = ma_pred_order - (ma_pred_order % 2);
    for (i = 0; i < limit; i += 2) {
        mr_energy += quant_energy[i] * ma_prediction_coeff[i];
        mr_energy += quant_energy[i + 1] * ma_prediction_coeff[i + 1];
    }
    // Handle remaining element if ma_pred_order is odd
    if (i < ma_pred_order) {
        mr_energy += quant_energy[i] * ma_prediction_coeff[i];
    }
}
