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
    // Variant 2: Reverse consecutive memory access (access arrays from end to start)
    for (i = ma_pred_order - 1; i >= 0; i--) {
        mr_energy += quant_energy[i] * ma_prediction_coeff[i];
    }
}
