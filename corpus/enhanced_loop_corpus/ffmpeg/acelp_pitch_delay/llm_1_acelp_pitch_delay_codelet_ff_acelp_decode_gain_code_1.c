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
    if (ma_pred_order > 0) {
        for (i = 0; i < ma_pred_order; i += 2) {
            mr_energy += quant_energy[i] * ma_prediction_coeff[i];
            if (i + 1 < ma_pred_order)
                mr_energy += quant_energy[i + 1] * ma_prediction_coeff[i + 1];
        }
    }
}
